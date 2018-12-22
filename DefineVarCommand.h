//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_DEFINEVARCOMMAND_H
#define FIRSTSTONE_DEFINEVARCOMMAND_H

#include "Command.h"
#include "Shunting.h"
class DefineVarCommand : public Command {
    int execute(vector<string> st);
    int execute(vector<string> str,map<string,string>symbolTableNamePath, map<string,double >symbolTablePathDouble
            ,  map<string,double >symbolTableNameDouble);
};


#endif //FIRSTSTONE_DEFINEVARCOMMAND_H
