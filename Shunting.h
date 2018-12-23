//
// Created by user on 12/19/2018.
//

#ifndef FIRSTSTONE_SHUNTING_H
#define FIRSTSTONE_SHUNTING_H

#include <map>
#include "Expression.h"
#include "stack"

using namespace std;

class Shunting {
    map<char, int> op_dictionary = {{'(',0}, {')',0},
                                    {'-',1}, {'+',1},
                                    {'*',2}, {'/',2}
    };
private:
    PlaneData *planeData;
public:
    Shunting(PlaneData *planeData);
    void initializeMap();
    bool isParam(string tokens);
    int precedence(char operation);
    int operationPriority(char operation);
    Expression *createExpression(string tokens);
    Expression* applyOp(Expression* val1, Expression* val2, char operation);
};



#endif //FIRSTSTONE_SHUNTING_H
