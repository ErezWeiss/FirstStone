//
// Created by user on 12/19/2018.
//

#include <chrono>
#include <thread>
#include "SleepCommand.h"
#include "Shunting.h"

SleepCommand::SleepCommand() {
}

int SleepCommand::calculate(vector<string>str) {
    Shunting shunting;
    //cast 'double' into the receiver type 'int'
    int millisec = static_cast<int>(shunting.createExpression(str[1])->calculate());
    this_thread::sleep_for(chrono::milliseconds(millisec));
    return 0;
}