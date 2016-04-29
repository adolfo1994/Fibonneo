//
// Created by adolfo on 10/04/16.
//

#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Message.h"


std::string Message::buildString() {
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(4) << counter;
    stream << std::setfill('0') << std::setw(4) << note_1;
    stream << std::setfill('0') << std::setw(4) << note_2;

    hash = std::hash<std::string>{}(stream.str());
    stream << std::setfill('0') << std::setw(20) << hash;

    return stream.str();
}


Message Message::buildFromBuffer(std::string buffer) {
    Message result = Message();
    result.counter = atoi(buffer.substr(0, 4).c_str());
    result.note_1 = atoi(buffer.substr(4, 4).c_str());
    result.note_2 = atoi(buffer.substr(8, 4).c_str());

    std::stringstream stream(buffer.substr(12));
    stream >> result.hash;

    return result;
}


const std::size_t Message::message_size = 36;
