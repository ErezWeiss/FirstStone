//
// Created by erez on 12/18/18.
//פסודו קוד

#ifndef FIRSTSTONE_CONDITIONPARSER_H
#define FIRSTSTONE_CONDITIONPARSER_H


#include <list>
#include "Shunting.h"
#include "Command.h"
#include "Parser.h"

class ConditionParser : public Command {
private:
    Parser * parser;
    map<string, CommandExpression*> expressionMap;
public:
    void setParser(Parser *parser);

    void setExpressionMap(const map<string, CommandExpression *> &expressionMap);


public:
    bool conditionCheck();
    int execute();

};


#endif //FIRSTSTONE_CONDITIONPARSER_H
