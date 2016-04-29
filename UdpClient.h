//
// Created by adolfo on 28/04/16.
//

#ifndef FIBONNEO_UDPCLIENT_H
#define FIBONNEO_UDPCLIENT_H

#include <iostream>
#include <chrono>

#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>

#include "Client.h"


using Clock = std::chrono::high_resolution_clock;

class UdpClient:public Client {
private:
    std::string server_ip;
    uint16_t server_port;
    struct sockaddr_in addr;
    int sock;
    std::chrono::time_point<Clock> start_time;
    std::chrono::time_point<Clock> end_time;
public:

    UdpClient(std::string server_ip, uint16_t server_port) : server_ip(server_ip), server_port(server_port) {
    }

    virtual void connect_socket() override;

    virtual void send_message(Message msg) override;

    virtual Confirmation get_confirmation() override;

    virtual std::chrono::duration<double> get_duration() override;


};


#endif //FIBONNEO_UDPCLIENT_H
