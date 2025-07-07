// proxy_server.hpp
#ifndef PROXY_SERVER_HPP
#define PROXY_SERVER_HPP

#include <string>
#include <thread>
#include <unordered_map>
#include <mutex>
#include <netinet/in.h>

class ProxyServer {
private:
    int server_fd;
    int port;
    void handleClient(int client_fd);
    void setupServerSocket();

public:
    ProxyServer(int port);
    void start();
};

#endif // PROXY_SERVER_HPP