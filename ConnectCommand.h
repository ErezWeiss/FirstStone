//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_CONNECTCOMMAND_H
#define FIRSTSTONE_CONNECTCOMMAND_H


#include "Command.h"
#include "Shunting.h"
class ConnectCommand : public Command{
private:
    string ip_address;
    int port;
public:
    ConnectCommand();
    int execute();
    const string &getIp_address() const;
    void setIp_address(const string &ip_address);
    void SetValueInGame(string pathAndNewValue);
};


#endif //FIRSTSTONE_CONNECTCOMMAND_H
