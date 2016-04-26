//
// Created by adolfo on 10/04/16.
//

#include <sstream>
#include <iostream>
#include <cstring>
#include "Message.h"

std::string Message::buildString() {
    std::stringstream stream;
    stream << counter;
    stream << note_1;
    stream << note_2;
    stream << hash;
    return stream.str();

}
