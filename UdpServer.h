//
// Created by alculquicondor on 4/27/16.
//

#ifndef FIBONNEO_UDPSERVER_H
#define FIBONNEO_UDPSERVER_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#include "Server.h"


class UdpServer : public Server {
public:
    UdpServer(uint16_t port);
    virtual void accept_connection();
    virtual Message get_message();
    virtual void send_confirmation(const Confirmation &confirmation);

private:
    int socket_fd;
    sockaddr_in remote_addr;
    socklen_t addr_len;
};


#endif //FIBONNEO_UDPSERVER_H
