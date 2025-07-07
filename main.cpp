#include "proxy_server.hpp"

int main() {
    ProxyServer server(8080); // Start on port 8080
    server.start();
    return 0;
}