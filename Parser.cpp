//
// Created by erez on 12/18/18.
//

#include "Parser.h"
#include "OpenServerCommand.h"
#include "CommandExpression.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "WhileCommand.h"

Parser::Parser(vector<string> &strings){
    this->strings = strings;
    this->expressionMap.insert(pair<string,Expression*>("openDataServer", new CommandExpression(new OpenServerCommand));
    this->expressionMap.insert(pair<string,Expression*>("connect", new CommandExpression(new ConnectCommand));
    this->expressionMap.insert(pair<string,Expression*>("var", new CommandExpression(new DefineVarCommand));
    this->expressionMap.insert(pair<string,Expression*>("while", new CommandExpression(new WhileCommand));
}

