//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_CONNECTCOMMAND_H
#define FIRSTSTONE_CONNECTCOMMAND_H


#include "Command.h"
#include "Shunting.h"
class ConnectCommand : public Command{
    string ip_address;
    double port;
public:

    ConnectCommand();

    int calculate(vector<string> str) override;

    const string &getIp_address() const;

    void setIp_address(const string &ip_address);
};


#endif //FIRSTSTONE_CONNECTCOMMAND_H
