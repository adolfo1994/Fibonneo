//
// Created by adolfo on 10/04/16.
//
#include <map>
#include <vector>
#include <iostream>
#ifndef FIBONNEO_HISTOGRAM_H
#define FIBONNEO_HISTOGRAM_H


class Histogram {


public:
    const std::map<std::string, std::vector<float> > &getValues() const {
        return this->values;
    }

    void setValues(const std::map<std::string, std::vector<float> > &values) {
        Histogram::values = values;
    }
    void draw();
    bool add_measure(std::string protocol, float value);

    Histogram(const std::map<std::string, std::vector<float>> &values,
              float &max_value) : values(values), max_value(max_value){
    }

private:
    std::map<std::string, std::vector<float> > values;
    float max_value;
};


#endif //FIBONNEO_HISTOGRAM_H
