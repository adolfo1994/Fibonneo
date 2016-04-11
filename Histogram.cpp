//
// Created by adolfo on 10/04/16.
//

#include <string>
#include "Histogram.h"

void Histogram::draw() {
    // TODO
    return;
}


bool Histogram::add_measure(std::string protocol, float value) {
    if(this->values.end() != this->values.find(protocol)){
        this->values[protocol].push_back(value);
        return true;
    }else{
        return false;
    }
}

