//
// Created by erez on 12/18/18.
//

#include "DefineVarCommand.h"

int DefineVarCommand::execute() {
    if (this->params[2]=="bind"){
        this->planeData->getSymbolTableNamePath().insert(this->params[1],this->params[3]);
    } else{
        Shunting shunting = Shunting(this->planeData);
        Expression * expression = shunting.createExpression(this->params[2]);
        this->planeData->getSymbolTableNameDouble().insert(pair<string,double >(this->params[2],expression->calculate()));
    }
}