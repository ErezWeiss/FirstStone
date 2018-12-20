//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_COMMANDEXPRESSION_H
#define FIRSTSTONE_COMMANDEXPRESSION_H


#include "Expression.h"
#include "Command.h"

class CommandExpression : public Expression{
private:
    Command* cmd;
public:
    CommandExpression(Command* cmd); //CTOR
    double calculate(vector<string> str) const;
    double calculate() const;
};


#endif //FIRSTSTONE_COMMANDEXPRESSION_H
