//
// Created by jose on 10/04/16.
//
#include <sstream>
#include <iomanip>
#include <cstring>
#include "Confirmation.h"
#include <iostream>

inline bool charToBool(const char letter) {
   return letter == '1';
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
    stream << paddingIp(ip);
    stream << correct;
    return stream.str();
}

Confirmation Confirmation::buildFromBuffer(std::string buffer) {
    Confirmation result;
    result.correct = charToBool(buffer.back());
    result.ip = takeOutLeftZeros(buffer.substr(0, buffer.size()-1)).c_str();

    return result;
}
