//
// Created by user on 12/20/2018.
//

#include <iostream>
#include "PrintCommand.h"
#include "Shunting.h"

int PrintCommand::execute() {
        Shunting shunting = Shunting(this->planeData);
        std::cout<<shunting.createExpression(params[1])->calculate()<<endl;
}