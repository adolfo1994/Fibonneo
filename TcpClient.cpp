//
// Created by adolfo on 29/04/16.
//

#include "TcpClient.h"

void TcpClient::connect_socket() {
    this->sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    memset(&this->addr, 0, sizeof(struct sockaddr_in));
    this->addr.sin_family = AF_INET;
    this->addr.sin_port = htons(this->server_port);
    inet_pton(AF_INET, this->server_ip.c_str(), &this->addr.sin_addr);

    connect(this->sock, (const struct sockaddr *)&this->addr, sizeof(struct sockaddr_in));
}

void TcpClient::send_message(Message msg) {
    std::string message = msg.buildString();
    this->start_time = std::chrono::system_clock::now();
    if (send(sock, message.c_str(), message.size(), 0) < 0) {
        this->queue_end_time = std::chrono::system_clock::now();
        perror("Send failed : ");
        return;
    }
    this->queue_end_time = std::chrono::system_clock::now();
}

Confirmation TcpClient::get_confirmation() {
    std::string buffer(Confirmation::message_size, 0);

    //Receive a reply from the server
    if( recv(this->sock, &buffer[0] , buffer.size(), 0) < 0)
    {
        this->end_time = std::chrono::system_clock::now();
        std::cerr << "Failed to receive" << std::endl;
        return Confirmation();

    }
    this->end_time = std::chrono::system_clock::now();
    return Confirmation::buildFromBuffer(buffer);
}

std::chrono::duration<double> TcpClient::get_duration() {
    return end_time - start_time;
}

std::chrono::duration<double> TcpClient::get_queuing_duration() {
    return queue_end_time - start_time;
}
