//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_BINARYEXPRESSION_H
#define FIRSTSTONE_BINARYEXPRESSION_H


#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression* left;
    Expression* right;
public:
    BinaryExpression(Expression* left, Expression* right){
        this->left = left;
        this->right = right;
    }
    virtual double calculate() const = 0;
};


#endif //FIRSTSTONE_BINARYEXPRESSION_H
