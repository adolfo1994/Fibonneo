//
// Created by adolfo on 10/04/16.
//
#include "Histogram.h"
#include "Synthesizer.h"
#include "Server.h"
#include "Client.h"
#ifndef FIBONNEO_FIBONNEO_H
#define FIBONNEO_FIBONNEO_H


class Fibonneo {

private:
    Server server;
    Client client;
    Synthesizer synth;
    Histogram hist;


public:
    Fibonneo(const Server &server, const Client &client, const Synthesizer &synth, const Histogram &hist) : server(
            server), client(client), synth(synth), hist(hist) { }

    virtual ~Fibonneo() { }

public:
    const Server &getServer() const {
        return server;
    }

    void setServer(const Server &server) {
        Fibonneo::server = server;
    }

    const Client &getClient() const {
        return client;
    }

    void setClient(const Client &client) {
        Fibonneo::client = client;
    }

    const Synthesizer &getSynth() const {
        return synth;
    }

    void setSynth(const Synthesizer &synth) {
        Fibonneo::synth = synth;
    }

    const Histogram &getHist() const {
        return hist;
    }

    void setHist(const Histogram &hist) {
        Fibonneo::hist = hist;
    }
    int calc_note();
    void play_note(int note);
    float calc_delays();
    void run();

};


#endif //FIBONNEO_FIBONNEO_H
