//
// Created by erez on 12/18/18.
//

#include "EqualCommand.h"

int EqualCommand::execute() {
    if (str[1]=="bind"){
        symbolTableNamePath.insert(str[0],str[2]);
    } else{
        Shunting shunting = Shunting();
        Expression * expression = shunting.createExpression(str[1]);
        symbolTableNameDouble.insert(pair<string,double >(str[1],expression->calculate()));
    }
}