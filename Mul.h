//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_MUL_H
#define FIRSTSTONE_MUL_H


#include "BinaryExpression.h"

class Mul : BinaryExpression {
public:
    Mul(Expression* left, Expression* right) : BinaryExpression(left, right){

    }
    virtual double calculate() const;
};


#endif //FIRSTSTONE_MUL_H
