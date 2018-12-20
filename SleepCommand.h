//
// Created by user on 12/19/2018.
//

#ifndef FIRSTSTONE_SLEEPCOMMAND_H
#define FIRSTSTONE_SLEEPCOMMAND_H


#include "Command.h"

class SleepCommand : public Command {
public:
    SleepCommand();
    int calculate(vector<string> str) override;
};

#endif //FIRSTSTONE_SLEEPCOMMAND_H
