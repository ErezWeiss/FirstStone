//
// Created by user on 12/20/2018.
//

#include "PrintCommand.h"

int DefineVarCommand::calculate(vector<string> str) {
        Shunting shunting = Shunting();
        cout<<shunting.createExpression(str[1])->calculate()<<endl;
}