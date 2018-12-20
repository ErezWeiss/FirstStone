//
// Created by user on 12/19/2018.
//

#include "SleepCommand.h"

Sleep::Sleep(string& millisec) {
    Shunting shunting;
    //cast 'double' into the receiver type 'int'
    this->millisec = static_cast<int>
    (shuntingYard.createExpression(millisec)->calculate());
}

double Sleep::execute() {
    this_thread::sleep_for(chrono::milliseconds(this->millisec));
    return 0;
}