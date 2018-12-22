//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_COMMAND_H
#define FIRSTSTONE_COMMAND_H

#include <string>
#include <vector>
#include "PlaneData.h"

using namespace std;

class Command {
public:
    virtual int execute(vector<string> str, PlaneData *planeData) = 0;
};


#endif //FIRSTSTONE_COMMAND_H
