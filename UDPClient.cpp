//
// Created by adolfo on 28/04/16.
//
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include "UDPClient.h"
#include "Confirmation.h"

void UDPClient::connect_socket() {
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

    inet_pton(AF_INET, this->server_ip.c_str() ,&this->addr.sin_addr.s_addr);

    this->addr.sin_port=htons(std::stoi(this->server_port));

}

void UDPClient::send_message(Message msg) {
    this->start_time = std::chrono::system_clock::now();
    if(sendto(this->sock, msg.buildString().c_str(), msg.buildString().size(), 0,
       (struct sockaddr *)&this->addr, sizeof(this->addr))!=msg.buildString().size()) {
        perror("Mismatch in number of bytes sent");
        exit(EXIT_FAILURE);
    }
}

Confirmation UDPClient::get_confirmation() {
    int received(0);
    int addrLength(sizeof(this->addr));
    char buffer[256] = {0};
    if((received=recvfrom(this->sock, buffer, 256, 0, (sockaddr *)&this->addr, (socklen_t*)&addrLength)) < 0) {
        this->end_time = std::chrono::system_clock::now();
        perror("Mismatch in number of bytes received");
        Confirmation confirmation(buffer, false);
        return confirmation;
    }
    this->end_time = std::chrono::system_clock::now();
    Confirmation confirmation(buffer, true);

    return confirmation;
}

std::chrono::duration<double> UDPClient::get_duration() {
    return this->start_time - this->end_time;
}







