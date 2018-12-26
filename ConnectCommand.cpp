//
// Created by erez on 12/18/18.
//

#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <zconf.h>
#include "ConnectCommand.h"
#include <pthread.h>
#include <thread>



ConnectCommand::ConnectCommand() {
}

//void ConnectCommand::setOpenClientSocket(OpenClientSocket *openClientSocket) {
//    ConnectCommand::openClientSocket = openClientSocket;
//}

const string &ConnectCommand::getIp_address() const {
    return ip_address;
}

void ConnectCommand::setIp_address(const string &ip_address) {
    ConnectCommand::ip_address = ip_address;
}

int ConnectCommand::execute() {
    this->ip_address = params[1];
    this->planeData->setIp_address(this->ip_address);
    this->port = (int)shunting->createExpression(params[2])->calculate();
    this->planeData->setPort(this->port);
    this->myParameters = new MyParameters();
    this->myParameters->portNum = port;
    this->myParameters->ip = ip_address;
    this->myParameters->planeData=this->planeData;
    pthread_t pthreadID;
    pthread_create(&pthreadID, nullptr, openNewClientSocket, this->myParameters);
    pthread_join(pthreadID, nullptr);
}

void* ConnectCommand::openNewClientSocket(void *args) {
    struct MyParameters *parameters;
    parameters = (struct MyParameters*) args;
    parameters->planeData->openSocket(parameters->ip, parameters->portNum);
}


void ConnectCommand::setOpenClientSocket(OpenClientSocket *openClientSocket) {
    ConnectCommand::openClientSocket = openClientSocket;
}


