//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_CONNECTCOMMAND_H
#define FIRSTSTONE_CONNECTCOMMAND_H


#include "Command.h"
#include "Shunting.h"
#include "OpenClientSocket.h"
struct MyParameters {
    string ip;
    int portNum;
    PlaneData* planeData;
};
class ConnectCommand : public Command{


private:
    string ip_address;
    int port;
    MyParameters *myParameters;
    OpenClientSocket *openClientSocket;

public:
    ConnectCommand();
    int execute();
    const string &getIp_address() const;
    void setIp_address(const string &ip_address);
    void SetValueInGame(string pathAndNewValue);
    static void* openNewClientSocket(void* args);

    void setOpenClientSocket(OpenClientSocket *openClientSocket);

};


#endif //FIRSTSTONE_CONNECTCOMMAND_H
