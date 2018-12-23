//
// Created by erez on 12/18/18.
//

#include "EqualCommand.h"

int EqualCommand::execute() {
    if (this->params[1]=="bind"){
        this->planeData->getSymbolTableNamePath().insert(this->params[0],this->params[2]);
    } else{
        Shunting shunting(this->planeData) ;
        Expression * expression = shunting.createExpression(this->params[1]);
        this->planeData->getSymbolTableNameDouble().insert(pair<string,double >(this->params[1],expression->calculate()));
    }
}