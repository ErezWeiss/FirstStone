//
// Created by user on 12/20/2018.
//

#include "PrintCommand.h"

int PrintCommand::execute() {
        Shunting shunting = Shunting();
        cout<<shunting.createExpression(str[1])->calculate()<<endl;
}