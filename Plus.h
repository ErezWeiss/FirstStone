//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_PLUS_H
#define FIRSTSTONE_PLUS_H


#include "BinaryExpression.h"

class Plus : public BinaryExpression {
public:
    Plus(Expression* left, Expression* right) : BinaryExpression(left, right){

    }
    virtual double calculate() const;
};


#endif //FIRSTSTONE_PLUS_H
