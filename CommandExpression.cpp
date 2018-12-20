//
// Created by erez on 12/18/18.
//

#include "CommandExpression.h"

CommandExpression::CommandExpression(Command* cmd){
    this->cmd = cmd;
}
double CommandExpression::calculate(vector<string> str) const{
    return cmd->calculate(str); // hey brother
}