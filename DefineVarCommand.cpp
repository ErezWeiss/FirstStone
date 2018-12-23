//
// Created by erez on 12/18/18.
//

#include "DefineVarCommand.h"

int DefineVarCommand::execute() {
    if (str[2]=="bind"){
        symbolTableNamePath.insert(str[1],str[3]);
    } else{
        Shunting shunting = Shunting();
        Expression * expression = shunting.createExpression(str[2]);
        symbolTableNameDouble.insert(pair<string,double >(str[2],expression->calculate()));
    }
}