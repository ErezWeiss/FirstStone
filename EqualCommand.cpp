//
// Created by erez on 12/18/18.
//

#include "EqualCommand.h"

int EqualCommand::execute() {

    if (this->params[1]=="bind"){ //breaks = bind "/controls/flight/speedbrake"
        this->planeData->AddToSymbolTableNamePath(this->params[0],this->params[2]);
    } else {
        string varName = this->params[1];
        string value = this->params[2];
        string path = this->planeData->getSymbolTableNamePath()[varName];
        string final = path.append(" ");
        final.append(value);
        this->planeData->writeToSimulator(final.c_str());
    }
}

//if (this->params[1]=="bind"){ //breaks = bind "/controls/flight/speedbrake"
//this->planeData->AddToSymbolTableNamePath(this->params[0],this->params[2]);
//} else { //var h0 = heading
//Shunting shunting = Shunting(this->planeData);
//Expression * expression = shunting.createExpression(this->params[1]);
//this->planeData->AddToSymbolTableNameDouble(this->params[0],expression->calculate());
//}