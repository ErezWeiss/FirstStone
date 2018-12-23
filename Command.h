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
private:
    vector<string> params;
public:
//    virtual int execute() = 0;
    virtual int execute() = 0;
    virtual void setPlaneData(PlaneData * planeData);
    void setParams(vector<string> params){
        this->params = params;
    }
};


#endif //FIRSTSTONE_COMMAND_H
