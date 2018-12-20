//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_COMMAND_H
#define FIRSTSTONE_COMMAND_H

#include <string>
#include <vector>

using namespace std;

class Command {
public:
    virtual int calculate(vector<string> str) = 0;
};


#endif //FIRSTSTONE_COMMAND_H
