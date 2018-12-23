//
// Created by erez on 12/18/18.
//פסודו קוד

#ifndef FIRSTSTONE_CONDITIONPARSER_H
#define FIRSTSTONE_CONDITIONPARSER_H


#include <list>
#include "Shunting.h"
#include "Command.h"

class ConditionParser : public Command {
private:
    vector<string> str;
    list<Command*> cmds;
public:
    ConditionParser();
    bool conditionCheck();
    int execute();

};


#endif //FIRSTSTONE_CONDITIONPARSER_H
