//
// Created by jose on 10/04/16.
//

#ifndef FIBONNEO_CONFIRMATION_H
#define FIBONNEO_CONFIRMATION_H


#include <string>

class Confirmation {
public:
    Confirmation() {
        ip = new char[15];
    }

    Confirmation(char *ip, bool correct) : ip(ip), correct(correct) { }

    virtual ~Confirmation() {
    }

    const char *getIp() const {
        return ip;
    }

    bool isCorrect() const {
        return correct;
    }

    void setCorrect(bool correct) {
        Confirmation::correct = correct;
    }

    std::string buildString() const;

private:
    char* ip;
    bool correct;

};


#endif //FIBONNEO_CONFIRMATION_H
