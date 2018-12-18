//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_CONNECTCOMMAND_H
#define FIRSTSTONE_CONNECTCOMMAND_H


#include "Command.h"

class ConnectCommand : public Command{
    int execute(vector<string> &str, int index) override;
};


#endif //FIRSTSTONE_CONNECTCOMMAND_H
