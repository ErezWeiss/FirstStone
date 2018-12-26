//
// Created by erez on 12/18/18.
//


#ifndef FIRSTSTONE_OPENSERVERCOMMAND_H
#define FIRSTSTONE_OPENSERVERCOMMAND_H
#include "Command.h"

struct arg_struct {
    int portForListen;
    int UpdatesPerSecond;

//    virtual ~arg_struct();

    PlaneData *planeData;
};
class OpenServerCommand : public Command {

private:
    struct arg_struct * args;
public:
    bool isDidTheGameSentSomething() const;
    void changeIsDidTheGameSentSomething();
    int execute();
    ~OpenServerCommand();
    };


#endif //FIRSTSTONE_OPENSERVERCOMMAND_H
