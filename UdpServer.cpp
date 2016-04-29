//
// Created by alculquicondor on 4/27/16.
//

#include "UdpServer.h"


UdpServer::UdpServer(uint16_t port) {
    sockaddr_in my_addr;

    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    memset((char *)&my_addr, 0, sizeof my_addr);
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    my_addr.sin_port = htons(port);

    addr_len = sizeof remote_addr;
}


void UdpServer::accept_connection() {
    // No connection required for UDP
}


Message UdpServer::get_message() {
    std::string buffer(Message::message_size, 0);
    recvfrom(socket_fd, &buffer[0], buffer.size(), 0, (sockaddr *)&remote_addr, &addr_len);
    return Message::buildFromBuffer(buffer);
}


void UdpServer::send_confirmation(const Confirmation &confirmation) {
    std::string msg = confirmation.buildString();
    sendto(socket_fd, msg.c_str(), msg.size(), 0, (sockaddr *)&remote_addr, addr_len);
}
