//
// Created by erez on 12/18/18.
//


#ifndef FIRSTSTONE_OPENSERVERCOMMAND_H
#define FIRSTSTONE_OPENSERVERCOMMAND_H
#include "Command.h"


class OpenServerCommand : public Command {
public:
    bool isDidTheGameSentSomething() const;
    void changeIsDidTheGameSentSomething();
    int execute();
    };


#endif //FIRSTSTONE_OPENSERVERCOMMAND_H
