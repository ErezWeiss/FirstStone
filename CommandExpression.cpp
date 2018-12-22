//
// Created by erez on 12/18/18.
//

#include "CommandExpression.h"

CommandExpression::CommandExpression(Command* cmd){
    this->cmd = cmd;
}
double CommandExpression::execute(vector<string> str) const{
    return cmd->execute(str); // hey brother
}