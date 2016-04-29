#include <iostream>

#include "TcpServer.h"
#include "UdpServer.h"
#include "TcpClient.h"
#include "UdpClient.h"
#include "Fibonneo.h"


using namespace std;

void show_my_ip() {
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
            cerr << ifa->ifa_name << ": " << host << endl;
        }
    }
    freeifaddrs(ifaddr);
}


int main() {
    uint16_t port = 9000;
    show_my_ip();
    cerr << "TCP(T)/UDP(u): ";
    string input;
    cin >> input;
    bool tcp = input[0] == 'T' or input[0] == 't';
    Server *server;
    if (tcp)
        server = new TcpServer(port);
    else
        server = new UdpServer(port);
    server->accept_connection();
    cerr << "Next node IP: ";
    cin >> input;
    Client *client;
    if (tcp)
        client = new TcpClient(input, port);
    else
        client = new UdpClient(input, port);
    client->connect_socket();

    Fibonneo fibonneo(cerr, cout, server, client);

    cerr << "Is start? (Y/n): ";
    cin >> input;
    if (input[0] == 'y' or input[0] == 'Y') {
        int f0, f1, rep;

        cerr << "Note 0: ";
        cin >> f0;
        cerr << "Note 1: ";
        cin >> f1;
        cerr << "Repetitions: ";
        cin >> rep;
        fibonneo.start(rep, f0, f1);
    }
    while (true) {
        fibonneo.receive_send();
    }
    return 0;
}