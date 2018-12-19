//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_NUMBER_H
#define FIRSTSTONE_NUMBER_H


#include <cmath>
#include "Expression.h"

class Number : public Expression {
private:
    double num;
public:
    Number(double num);
    double calculate() const;
    // note
};


#endif //FIRSTSTONE_NUMBER_H
