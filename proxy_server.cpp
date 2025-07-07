// proxy_server.cpp
#include "proxy_server.hpp"
#include "cache.hpp"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>

Cache cache;

ProxyServer::ProxyServer(int port) : port(port) {}

void ProxyServer::setupServerSocket() {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 10);
    std::cout << "Proxy server started on port " << port << "...\n";
}

void ProxyServer::start() {
    setupServerSocket();
    while (true) {
        int client_fd = accept(server_fd, nullptr, nullptr);
        std::thread(&ProxyServer::handleClient, this, client_fd).detach();
    }
}

void ProxyServer::handleClient(int client_fd) {
    char buffer[8192] = {0};

    // 1. Receive client request
    ssize_t bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
    if (bytes_received <= 0) {
        std::cerr << "[ERROR] Failed to receive data or connection closed by client.\n";
        close(client_fd);
        return;
    }

    std::cout << "\n[INFO] Received request from client (FD: " << client_fd << ")\n";
    std::cout << "[RAW REQUEST]:\n" << std::string(buffer, bytes_received) << "\n";

    std::string request(buffer);
    size_t host_pos = request.find("Host: ");
    if (host_pos == std::string::npos) {
        std::cerr << "[WARN] 'Host' header not found in request.\n";
        close(client_fd);
        return;
    }

    // 2. Extract the URL
    std::string url = request.substr(host_pos + 6);
    url = url.substr(0, url.find("\r\n"));

    std::cout << "[DEBUG] Parsed Host: " << url << "\n";

    // 3. Check cache
    if (cache.exists(url)) {
        std::cout << "[CACHE HIT] Returning cached response for " << url << "\n";
        std::string response = cache.get(url);
        ssize_t sent = send(client_fd, response.c_str(), response.length(), 0);
        if (sent < 0) {
            std::cerr << "[ERROR] Failed to send cached response to client.\n";
        } else {
            std::cout << "[INFO] Sent " << sent << " bytes from cache.\n";
        }
    } else {
        std::cout << "[CACHE MISS] Generating dummy response for " << url << "\n";

        // You can make this dynamic for testing
        std::string response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, Proxy!";
        cache.store(url, response);
        ssize_t sent = send(client_fd, response.c_str(), response.length(), 0);
        if (sent < 0) {
            std::cerr << "[ERROR] Failed to send new response to client.\n";
        } else {
            std::cout << "[INFO] Sent " << sent << " bytes as new response.\n";
        }
    }

    // 4. Close the connection
    std::cout << "[INFO] Closing connection with client (FD: " << client_fd << ")\n";
    close(client_fd);
}
