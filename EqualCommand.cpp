//
// Created by erez on 12/18/18.
//

#include "EqualCommand.h"

int EqualCommand::execute() {
    string varName = this->params[1];
    string value = this->params[2];
    string path = this->planeData->getSymbolTableNamePath()[varName];
    string final = path.append(" ");
    final.append(value);
    // "set controls/flight/rudder 0\r\n"
     this->planeData->SetValueInGame(final);
}