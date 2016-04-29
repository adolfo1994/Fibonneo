//
// Created by jose on 10/04/16.
//
#include <sstream>
#include <iomanip>
#include <cstring>
#include "Confirmation.h"
#include <iostream>

inline bool charToBool(const char letter) {
   return letter=='1'? true : false;
}

std::string paddingIp (std::string ip) {
    std::stringstream stream;
    std::string item;
    std::stringstream ip_string_stream(ip);
    while (getline(ip_string_stream, item, '.')) {
        stream << std::setfill('0') << std::setw(3) << item << ".";
    }

    return stream.str().substr(0, stream.str().size()-1);
}


std::string takeOutLeftZeros(std::string ip) {
    std::stringstream stream;
    std::string item;
    std::stringstream ip_string_stream(ip);
    while (getline(ip_string_stream, item, '.')) {
        stream << item.erase(0, item.find_first_not_of('0')) << ".";
    }
    return stream.str().substr(0, stream.str().size()-1);
}


std::string Confirmation::buildString() const {
    std::stringstream stream;
    stream << takeOutLeftZeros(ip);
    stream << correct;
    return stream.str();
}


Confirmation Confirmation::buildConfirmation(std::string ip, bool confirmation) {
    Confirmation result;
    result.ip = paddingIp(ip).c_str();
    result.correct = confirmation;

    return result;
}

Confirmation Confirmation::buildConfirmationFromBuffer(std::string buffer) {
    Confirmation result;
    result.correct = charToBool(buffer.back());
    result.ip = paddingIp(buffer.substr(0, buffer.size()-1)).c_str();

    return result;
}


std::string Confirmation::getIpWithoutZeros() {
    return takeOutLeftZeros(ip);
}
