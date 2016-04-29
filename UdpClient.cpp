//
// Created by adolfo on 28/04/16.
//
#include "UdpClient.h"

void UdpClient::connect_socket() {
    memset(&this->addr, 0, sizeof(this->addr));
    this->addr.sin_family=AF_INET;

    this->addr.sin_addr.s_addr=htonl(INADDR_ANY);
    this->addr.sin_port=htons(0);

    if((this->sock=socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    if(bind(this->sock,( struct sockaddr *) &this->addr, sizeof(this->addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    inet_pton(AF_INET, this->server_ip.c_str(), &this->addr.sin_addr);

    this->addr.sin_port=htons(this->server_port);

}

void UdpClient::send_message(Message msg) {
    this->start_time = std::chrono::system_clock::now();
    std::string message = msg.buildString();
    if (sendto(this->sock, message.c_str(), message.size(), 0,
               (struct sockaddr *) &this->addr, sizeof(this->addr)) != msg.buildString().size()) {
        perror("Mismatch in number of bytes sent");
        exit(EXIT_FAILURE);
    }
}

Confirmation UdpClient::get_confirmation() {
    int addrLength(sizeof(this->addr));
    std::string buffer(Confirmation::message_size, 0);
    if(recvfrom(this->sock, &buffer[0], buffer.size(), 0, (sockaddr *)&this->addr, (socklen_t*)&addrLength) < 0) {
        this->end_time = std::chrono::system_clock::now();
        perror("Mismatch in number of bytes received");
        return Confirmation();
    }
    this->end_time = std::chrono::system_clock::now();

    return Confirmation::buildFromBuffer(buffer);
}

std::chrono::duration<double> UdpClient::get_duration() {
    return this->start_time - this->end_time;
}







