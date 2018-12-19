//
// Created by erez on 12/18/18.
//

#include "DefineVarCommand.h"

int DefineVarCommand::execute(vector<string> &str, int index,symbolTableNamePath, symbolTablePathDouble,
        symbolTableNameDouble) {
    if (str[index+3]=="bind"){
        symbolTableNamePath.insert(str[index+1],str[index+4]);
    } else{
        new Expression
        symbolTableNameDouble.insert(str[index+1],str[index+3]);
    }
}
