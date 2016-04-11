//
// Created by jose on 10/04/16.
//

#include <cstring>
#include "Confirmation.h"

inline char boolToString(bool boolean){
    return boolean? '1' : '0';
}

char* Confirmation::buildString() {
    char* result_message = new char[17];
    char confirmation_flag = boolToString(correct);
    strcpy(result_message, ip);
    strcat(result_message, &confirmation_flag);
    result_message[16] = '\0';
    return result_message;
}