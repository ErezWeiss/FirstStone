#include <vector>
#include <netinet/in.h>
#include <zconf.h>
#include "OpenServerCommand.h"
#include "Shunting.h"
#define MAX_NUMBER 300

struct arg_struct {
    int portForListen;
    int UpdatesPerSecond;
    PlaneData *planeData;
};

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
            ssize_t erez = read(new_socket, buffer, MAX_NUMBER);
            args->planeData->ReadFromPlane(buffer);
//            std::this_thread::sleep_for(2s);                // made some problems...
        }
}

int OpenServerCommand::execute(vector<string> str, PlaneData *planeData) {
    Shunting shunting=Shunting();
    int portForListen = (int)shunting.createExpression(str[1])->calculate();
    int UpdatesPerSecond = (int)shunting.createExpression(str[2])->calculate();

    struct arg_struct args;
    args.portForListen = portForListen;
    args.UpdatesPerSecond = UpdatesPerSecond;
    args.planeData = planeData;
    pthread_t trid;
    pthread_create(&trid, nullptr, thread_func, (void *)&args);
    (void) pthread_join(trid, NULL);//////////////////////////////////////////option only
}


