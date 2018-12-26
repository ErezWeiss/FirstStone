//
// Created by user on 12/20/2018.
//

#include <iostream>
#include "PrintCommand.h"
#include <algorithm>

int PrintCommand::execute() {
        string toCheck = params[1];
        if ((toCheck.find('"') == std::string::npos)) { // if there is no " like this
                std::cout << shunting->createExpression(toCheck)->calculate() << endl;
        } else {
                string toBePrinted = params[1];
                toBePrinted.erase(std::remove(toBePrinted.begin(), toBePrinted.end(), '"'), toBePrinted.end());
                std::cout << toBePrinted << endl;
        }
}