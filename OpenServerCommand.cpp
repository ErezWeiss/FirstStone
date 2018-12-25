#include <vector>
#include <netinet/in.h>
#include <zconf.h>
#include <thread>
#include "OpenServerCommand.h"
#include "Shunting.h"
#include <chrono>
#define MAX_NUMBER 300
extern bool connectedGame;
struct arg_struct {
    int portForListen;
    int UpdatesPerSecond;
    PlaneData *planeData;
};

pthread_mutex_t lock;

void* thread_func(void* arguments) {
        struct arg_struct *args = (struct arg_struct *)arguments;
        int server_fd, new_socket, valread;
        char buffer[MAX_NUMBER];
        struct sockaddr_in address;
        int addrlen = sizeof(address);
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
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

        while(true) {
//            double readPerSecond = (double)args->UpdatesPerSecond;
//            readPerSecond = 1/readPerSecond;
            pthread_mutex_lock(&lock);
            ssize_t erez = read(new_socket, buffer, MAX_NUMBER);
            args->planeData->ReadFromPlane(buffer);
            connectedGame = true;
            pthread_mutex_unlock(&lock);
            std::this_thread::sleep_for(0.1s);          /// fix the time arg. the second arg...
        }
}

int OpenServerCommand::execute() {
    Shunting shunting(this->planeData);
    int portForListen = (int)shunting.createExpression(params[1])->calculate();
    int UpdatesPerSecond = (int)shunting.createExpression(params[2])->calculate();

    struct arg_struct args;
    args.portForListen = portForListen;
    args.UpdatesPerSecond = UpdatesPerSecond;
    args.planeData = planeData;
    pthread_t trid;
    pthread_create(&trid, nullptr, thread_func, (void *)&args);
//    (void) pthread_join(trid, NULL);
}



