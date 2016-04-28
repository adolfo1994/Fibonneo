//
// Created by alculquicondor on 4/27/16.
//

#ifndef FIBONNEO_SERVER_H
#define FIBONNEO_SERVER_H

#include "Message.h"
#include "Confirmation.h"


class Server {
public:
    virtual void accept_connection() = 0;
    virtual Message get_message() = 0;
    virtual void send_confirmation(const Confirmation &confirmation) = 0;
};

#endif //FIBONNEO_SERVER_H
