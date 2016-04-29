//
// Created by adolfo on 29/04/16.
//

#ifndef FIBONNEO_TCPCLIENT_H
#define FIBONNEO_TCPCLIENT_H


#include <iostream>
#include <chrono>

#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>

#include "Client.h"

using Clock = std::chrono::high_resolution_clock;

class TcpClient: public Client{
private:
    std::string server_ip;
    uint16_t server_port;
    struct sockaddr_in addr;
    int sock;
    std::chrono::time_point<Clock> start_time;
    std::chrono::time_point<Clock> end_time;

public:
    TcpClient(std::string server_ip, uint16_t server_port) : server_ip(server_ip), server_port(server_port) {
    }

    virtual void connect_socket() override;

    virtual void send_message(Message msg) override;

    virtual Confirmation get_confirmation() override;

    virtual std::chrono::duration<double> get_duration() override;

};


#endif //FIBONNEO_TCPCLIENT_H
