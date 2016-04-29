//
// Created by adolfo on 10/04/16.
//

#include "Fibonneo.h"


void Fibonneo::start(int counter, int f0, int f1) {
    Message message(counter - 1, f0, f1);
    output << f1 << std::endl;
    client->send_message(message);
    client->get_confirmation();
}

void Fibonneo::receive_send() {
    Message receive = server->get_message();
    server->send_confirmation(Confirmation(ip, 1));
    this->start_time = std::chrono::system_clock::now();
    int next_note = (receive.getNote_1() + receive.getNote_2()) % 10000;
    output << next_note << std::endl;
    this->end_time = std::chrono::system_clock::now();
    if (receive.getCounter()) {
        Message send(receive.getCounter() - 1, receive.getNote_2(), next_note);
        client->send_message(send);
        client->get_confirmation();
        double total_time = client->get_duration().count(), queuing_time = client->get_queuing_duration().count();
        timing << get_nodal_processing().count() * 1000 << ',' << queuing_time * 1000 << ',' <<
                (total_time - queuing_time) * 500 << std::endl;
    }
}

void Fibonneo::set_ip() {
    ifaddrs *ifaddr, *ifa;
    int family, s, n;
    char host[NI_MAXHOST];
    getifaddrs(&ifaddr);

    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
        if (ifa->ifa_addr == NULL)
            continue;
        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET && strcmp("lo", ifa->ifa_name) != 0) {
            getnameinfo(ifa->ifa_addr, sizeof(sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
            ip = std::string(host);
        }
    }
    freeifaddrs(ifaddr);
}

std::chrono::duration<double> Fibonneo::get_nodal_processing() {
    return end_time - start_time;
}
