//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_DEFINEVARCOMMAND_H
#define FIRSTSTONE_DEFINEVARCOMMAND_H

#include "Command.h"
#include "Shunting.h"
class DefineVarCommand : public Command {
    int execute();
};


#endif //FIRSTSTONE_DEFINEVARCOMMAND_H
