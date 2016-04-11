//
// Created by adolfo on 10/04/16.
//

#include <sstream>
#include <iostream>
#include <cstring>
#include "Message.h"

char* Message::buildString() {
    std::stringstream stream;
    stream << counter;
    stream << note_1;
    stream << note_2;
    stream << hash;
    char * result = new char [45];
    strcpy(result, stream.str().c_str());
    result [44] = '\0';
    return result;

}
