//
// Created by adolfo on 10/04/16.
//

#include "TcpServer.h"


TcpServer::TcpServer(uint16_t port) {
    socket_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in st_sock_addr;
    std::memset(&st_sock_addr, 0, sizeof st_sock_addr);
    st_sock_addr.sin_family = AF_INET;
    st_sock_addr.sin_port = htons(port);
    st_sock_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(socket_fd, (const sockaddr *)&st_sock_addr, sizeof st_sock_addr) == -1) {
        perror("bind failed");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(socket_fd, 10) == -1) {
        perror("listen failed");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }
}


void TcpServer::accept_connection() {
    client_fd = accept(socket_fd, NULL, NULL);
    if (client_fd < 0) {
        perror("accept failed");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }
}


Message TcpServer::get_message() {
    char buffer[44];
    read(client_fd, buffer, 44);
    return Message(); // TODO fix according to method
}


void TcpServer::send_confirmation(const Confirmation &confirmation) {
    std::string msg = confirmation.buildString();
    write(client_fd, msg.c_str(), msg.size());
}
