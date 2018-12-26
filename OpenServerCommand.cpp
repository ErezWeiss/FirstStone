#include <vector>
#include <netinet/in.h>
#include <zconf.h>
#include <pthread.h>
#include "OpenServerCommand.h"
#include <chrono>
#include <iostream>

#define MAX_NUMBER 300
extern bool connectedGame;
int server_fdGlobal;

void* thread_func(void* arguments) {
        struct arg_struct *args = (struct arg_struct*)arguments;
        int server_fd, new_socket, valread;
        char buffer[MAX_NUMBER];
        struct sockaddr_in address;
        int addrlen = sizeof(address);

        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        server_fdGlobal = server_fd;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons((uint16_t)args->portForListen);
        bind(server_fd, (struct sockaddr *) &address, sizeof(address));
        listen(server_fd, 5);

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
    connectedGame = true;
    while(true) {
        ssize_t erez = read(new_socket, buffer, MAX_NUMBER);
//        cout << buffer;
        args->planeData->ReadFromPlane(buffer);
    }
}

int OpenServerCommand::execute() {
    int portForListen = (int)shunting->createExpression(params[1])->calculate();
    int UpdatesPerSecond = (int)shunting->createExpression(params[2])->calculate();

//    struct arg_struct args;
    this->args = new arg_struct();
    this->args->portForListen = portForListen;
    this->args->UpdatesPerSecond = UpdatesPerSecond;
    this->args->planeData = planeData;
    pthread_t trid;
    pthread_create(&trid, nullptr, thread_func, this->args);
}

OpenServerCommand::~OpenServerCommand(){
    delete this->args;
    close(server_fdGlobal);
}
