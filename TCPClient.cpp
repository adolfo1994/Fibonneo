//
// Created by adolfo on 29/04/16.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <iostream>
#include "TCPClient.h"
#include <sys/socket.h>

void TCPClient::connect_socket() {
    this->sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    memset(&this->addr, 0, sizeof(struct sockaddr_in));
    this->addr.sin_family = AF_INET;
    this->addr.sin_port = htons(stoi(this->server_port));
    inet_pton(AF_INET, this->server_ip.c_str(), &this->addr.sin_addr);

    connect(this->sock, (const struct sockaddr *)&this->addr, sizeof(struct sockaddr_in));
}

void TCPClient::send_message(Message msg) {
    this->start_time = std::chrono::system_clock::now();
    if(send(sock , msg.buildString().c_str() , strlen( msg.buildString().c_str() ) , 0) < 0){
        perror("Send failed : ");
        return;
    }
}

Confirmation TCPClient::get_confirmation() {
    char buffer[256];
    std::string reply;

    //Receive a reply from the server
    if( recv(this->sock , buffer , sizeof(buffer) , 0) < 0)
    {
        this->end_time = std::chrono::system_clock::now();
        std::cout<<"Failed to receive"<<std::endl;
        return Confirmation(buffer, false);

    }
    this->end_time = std::chrono::system_clock::now();
    return Confirmation(buffer, true);
}

std::chrono::duration<double> TCPClient::get_duration() {
    return this->start_time - this->end_time;
}






