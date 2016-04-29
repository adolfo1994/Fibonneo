//
// Created by adolfo on 10/04/16.
//

#ifndef FIBONNEO_FIBONNEO_H
#define FIBONNEO_FIBONNEO_H

#include <ostream>
#include <cstring>

#include <ifaddrs.h>
#include <netdb.h>

#include "Server.h"
#include "Client.h"


using Clock = std::chrono::high_resolution_clock;

class Fibonneo {
public:
    Fibonneo(std::ostream &output, std::ostream &timing, Server *server, Client *client) :
            output(output), timing(timing), server(server), client(client) {
        set_ip();
        timing << "Nodal Processing,Queueing,Transmission+Propagation" << std::endl;
    }

    void start(int counter, int f0, int f1);

    void receive_send();

    std::chrono::duration<double> get_nodal_processing();

private:
    std::ostream &output, &timing;
    Server *server;
    Client *client;
    std::string ip;
    std::chrono::time_point<Clock> start_time, end_time;

    void set_ip();
};


#endif //FIBONNEO_FIBONNEO_H
