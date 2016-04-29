//
// Created by adolfo on 28/04/16.
//

#ifndef FIBONNEO_UDPCLIENT_H
#define FIBONNEO_UDPCLIENT_H

#include <iostream>
#include <chrono>
#include "Client.h"
#include "Message.h"

using Clock = std::chrono::high_resolution_clock;

class UDPClient:public Client {
private:
    std::string server_ip;
    std::string server_port;
    struct sockaddr_in addr;
    int sock;
    std::chrono::time_point<Clock> start_time;
    std::chrono::time_point<Clock> end_time;
public:

    UDPClient() {
        std::cout<<"Please input the server's IP: ";
        std::cin>>server_ip;
        std::cout<<"Please input the server's port: ";
        std::cin>>server_port;
    }

    virtual void connect_socket() override;

    virtual void send_message(Message msg) override;

    virtual Confirmation get_confirmation() override;

    virtual std::chrono::duration<double> get_duration() override;


};


#endif //FIBONNEO_UDPCLIENT_H
