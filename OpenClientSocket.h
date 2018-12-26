#ifndef EX3_OPENCLIENTSOCKET_H
#define EX3_OPENCLIENTSOCKET_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string>

using namespace std;

class OpenClientSocket {
    struct sockaddr_in server;
    int sockfd;
public:
    OpenClientSocket();

    void openSocket(string ip, double portNumber);

    virtual ~OpenClientSocket();

    void writeToSimulator(const char *buffer);

    int getSockfd() const;
};


#endif //EX3_OPENCLIENTSOCKET_H