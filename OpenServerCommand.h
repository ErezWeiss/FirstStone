//
// Created by erez on 12/18/18.
//


#include "Command.h"
#ifndef FIRSTSTONE_OPENSERVERCOMMAND_H
#define FIRSTSTONE_OPENSERVERCOMMAND_H


class OpenServerCommand : public Command {
    int calculate(vector<string> str) override;
};


#endif //FIRSTSTONE_OPENSERVERCOMMAND_H
