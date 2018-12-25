//
// Created by erez on 12/18/18.
//

#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <zconf.h>
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
    Shunting shunting(this->planeData);
    this->ip_address = params[1];
    this->planeData->setIp_address(this->ip_address);
    this->port = (int)shunting.createExpression(params[2])->calculate();
    this->planeData->setPort(this->port);
}
