//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_MINUS_H
#define FIRSTSTONE_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression{
public:
    Minus(Expression* left, Expression* right) : BinaryExpression(left, right){

    }
    virtual double calculate() const;
};


#endif //FIRSTSTONE_MINUS_H
