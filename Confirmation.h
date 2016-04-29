//
// Created by jose on 10/04/16.
//

#ifndef FIBONNEO_CONFIRMATION_H
#define FIBONNEO_CONFIRMATION_H


#include <string>

class Confirmation {
public:
    Confirmation() {
        correct = false;
    }

    Confirmation(std::string ip, bool correct) : ip(ip), correct(correct) { }

    virtual ~Confirmation() {
    }

    std::string getIp() const {
        return ip;
    }

    bool isCorrect() const {
        return correct;
    }

    void setCorrect(bool correct) {
        Confirmation::correct = correct;
    }

    std::string buildString() const;

    static Confirmation buildFromBuffer(std::string buffer);

    static const std::size_t message_size;

private:
    std::string ip;
    bool correct;

};


#endif //FIBONNEO_CONFIRMATION_H
