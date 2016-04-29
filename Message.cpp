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
    stream << std::setfill('0') << std::setw(32) << hash;

    return stream.str();
}


Message Message::buildMessage(std::string buffer) {
    Message result = Message();
    std::size_t hash = std::hash<std::string>{}(buffer);
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(32) << hash;
    result.counter = atoi(buffer.substr(0, 4).c_str());
    result.note_1 = atoi(buffer.substr(4, 4).c_str());
    result.note_2 = atoi(buffer.substr(8, 4).c_str());
    result.hash = stream.str().c_str();

    return result;
}
