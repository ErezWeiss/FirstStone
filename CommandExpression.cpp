//
// Created by erez on 12/18/18.
//

#include "CommandExpression.h"

CommandExpression::CommandExpression(Command* cmd){
    this->cmd = cmd;
}

void CommandExpression::SetParams(vector<string> vector){
    this->cmd->setParams(vector);
}

double CommandExpression::calculate() const{
    return cmd->execute(); // hey brother
}