#ifndef FIBONNEO_TCPSERVER_H
#define FIBONNEO_TCPSERVER_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#include "Server.h"


class TcpServer : public Server {
public:
    TcpServer(uint16_t port);
    virtual void accept_connection();
    virtual Message get_message();
    virtual void send_confirmation(const Confirmation &confirmation);
private:
    int socket_fd, client_fd;
};


#endif //FIBONNEO_TCPSERVER_H
