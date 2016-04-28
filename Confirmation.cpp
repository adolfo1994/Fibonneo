//
// Created by jose on 10/04/16.
//
#include <sstream>
#include <cstring>
#include "Confirmation.h"


inline char boolToString(bool boolean) {
    return boolean? '1' : '0';
}


inline bool charToBool(const char letter) {
   return letter=='1'? true : false;
}


std::string Confirmation::buildString() {
    std::stringstream stream;
    stream << ip;
    stream << correct;
    return stream.str();
}


Confirmation Confirmation::buildConfirmation(std::string buffer) {
    Confirmation result;
    result.ip = buffer.substr(0, 15).c_str();
    result.correct = charToBool(buffer.back());

    return result;

}