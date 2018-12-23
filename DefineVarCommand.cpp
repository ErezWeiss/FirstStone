//
// Created by erez on 12/18/18.
//

#include "DefineVarCommand.h"

int DefineVarCommand::execute() {
    if (params[2]=="bind"){
//        symbolTableNamePath.insert(str[1],str[3]);
    } else{
        Shunting shunting = Shunting(this->planeData);
        Expression * expression = shunting.createExpression(params[2]);
//        symbolTableNameDouble.insert(pair<string,double >(params[2],expression->calculate()));
    }
}