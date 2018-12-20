
Created by erez on 12/18/18.


#include <vector>
#include "OpenServerCommand.h"
#include "Shunting.h"

int OpenServerCommand::execute(vector<string> str) {
    Shunting shunting=Shunting();
    int portForListen = shunting.createExpression(str[1])->calculate();
    int UpdatesPerSecond = shunting.createExpression(str[2])->calculate();

    return 3;
}
