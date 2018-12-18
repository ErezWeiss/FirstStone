//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_DIV_H
#define FIRSTSTONE_DIV_H


#include "BinaryExpression.h"

class Div : BinaryExpression{
public:
    Div(Expression* left, Expression* right) : BinaryExpression(left, right){

    }
    virtual double calculate() const;
};


#endif //FIRSTSTONE_DIV_H
