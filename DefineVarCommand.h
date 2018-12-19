//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_DEFINEVARCOMMAND_H
#define FIRSTSTONE_DEFINEVARCOMMAND_H


#include "Command.h"

class DefineVarCommand : public Command {
    int execute(vector<string> &str, int index) override;
};


#endif //FIRSTSTONE_DEFINEVARCOMMAND_H
