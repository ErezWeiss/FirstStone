//
// Created by erez on 12/18/18.
//

#include "ConnectCommand.h"

ConnectCommand::ConnectCommand() {
}

const string &ConnectCommand::getIp_address() const {
    return ip_address;
}

void ConnectCommand::setIp_address(const string &ip_address) {
    ConnectCommand::ip_address = ip_address;
}

int ConnectCommand::execute() {
    Shunting* shunting=new Shunting(this->planeData);
    this->ip_address=params[1];        //..................
    this->ip_address=shunting->createExpression(params[2])->calculate();

}

