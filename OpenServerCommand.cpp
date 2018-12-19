//
// Created by erez on 12/18/18.
//

#include <vector>
#include "OpenServerCommand.h"

int OpenServerCommand::execute(vector<string> &str, int index) {
    int portForListen = stoi(str[index+1]);
    int UpdatesPerSecond = stoi(str[index+2]);

    return 3;
}
