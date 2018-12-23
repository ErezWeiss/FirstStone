//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_EXPRESSION_H
#define FIRSTSTONE_EXPRESSION_H


#include <vector>
#include "PlaneData.h"

class Expression {
public:
    virtual double calculate() const = 0;
//    virtual double calculate(vector<string> strings, PlaneData* planeData) const = 0;
};


#endif //FIRSTSTONE_EXPRESSION_H
