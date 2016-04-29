//
// Created by adolfo on 10/04/16.
//

#ifndef FIBONNEO_CLIENT_H
#define FIBONNEO_CLIENT_H

#include <chrono>
#include "Message.h"
#include "Confirmation.h"


class Client {
public:
    virtual void connect_socket() = 0;
    virtual void send_message(Message msg) = 0;
    virtual Confirmation get_confirmation() = 0;
    virtual std::chrono::duration<double> get_duration() = 0;
    virtual std::chrono::duration<double> get_queuing_duration() = 0;
};


#endif //FIBONNEO_CLIENT_H
