//
// Created by erez on 12/18/18.
//

#include "EqualCommand.h"

int EqualCommand::execute() {
    if (params[1]=="bind"){
//        symbolTableNamePath.insert(str[0],str[2]);
    } else{
        Shunting shunting = Shunting(this->planeData);
        Expression * expression = shunting.createExpression(params[1]);
//        symbolTableNameDouble.insert(pair<string,double >(str[1],expression->calculate()));
    }
}