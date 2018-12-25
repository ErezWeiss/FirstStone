//
// Created by erez on 12/18/18.
//

#include "DefineVarCommand.h"

int DefineVarCommand::execute() {
    if (this->params[2]=="bind"){ //var breaks = bind "/controls/flight/speedbrake"
        this->planeData->AddToSymbolTableNamePath(this->params[1],this->params[3]);
    } else { //var h0 = heading
        Shunting shunting = Shunting(this->planeData);
        Expression * expression = shunting.createExpression(this->params[2]);
        this->planeData->AddToSymbolTableNameDouble(this->params[1],expression->calculate());
    }
}