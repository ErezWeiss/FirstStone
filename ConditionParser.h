//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_CONDITIONPARSER_H
#define FIRSTSTONE_CONDITIONPARSER_H


#include <list>
#include "Command.h"

class ConditionParser : Command {
private:
    list<Command*> cmds;
};


#endif //FIRSTSTONE_CONDITIONPARSER_H
