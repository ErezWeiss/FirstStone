//
// Created by erez on 12/22/18.
//

#include <sstream>
#include <vector>
#include <sys/socket.h>
#include <netdb.h>
#include <strings.h>
#include "PlaneData.h"
#include <algorithm>
#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

#include <netinet/in.h>
extern bool connectedGame;

PlaneData::PlaneData() {

}

void PlaneData::AddToSymbolTableNamePath(string a, string b){
    this->symbolTableNamePath[a] = b;
}

void PlaneData::AddToSymbolTablePathDouble(string a, double b){
    this->symbolTablePathDouble[a] = b;
}
void PlaneData::AddToSymbolTableNameDouble(string a, double b){
    this->symbolTableNameDouble[a] = b;
}

double PlaneData::getValueByName(string str){
    //not found
    if (this->symbolTableNameDouble.find(str) == this->symbolTableNameDouble.end() ) {
        // found
        if(this->symbolTableNamePath.find(str) != this->symbolTableNamePath.end() ){
            return this->symbolTablePathDouble.find(this->symbolTableNamePath.find(str)->second)->second;
        } else{
            return 0;
        }
    }
        //found
    else{
        return this->symbolTableNameDouble.find(str)->second;
    }

    //should throw exception here couse there is no value for that parameter
}

void PlaneData::ReadFromPlane(string info){
    std::vector<double> vect;
    std::stringstream ss(info);
    double i;
    while (ss >> i)
    {
        vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }

    this->UpdateTheTable(vect);
}

void PlaneData::UpdateTheTable(vector<double> vector){
    this->symbolTablePathDouble["/instrumentation/airspeed-indicator/indicated-speed-kt"] = vector[0];
    this->symbolTablePathDouble["/instrumentation/altimeter/indicated-altitude-ft"] = vector[1];
    this->symbolTablePathDouble["/instrumentation/altimeter/pressure-alt-ft"] = vector[2];
    this->symbolTablePathDouble["/instrumentation/attitude-indicator/indicated-pitch-deg"] = vector[3];
    this->symbolTablePathDouble["/instrumentation/attitude-indicator/indicated-roll-deg"] = vector[4];
    this->symbolTablePathDouble["/instrumentation/attitude-indicator/internal-pitch-deg"] = vector[5];
    this->symbolTablePathDouble["/instrumentation/attitude-indicator/internal-roll-deg"] = vector[6];
    this->symbolTablePathDouble["/instrumentation/encoder/indicated-altitude-ft"] = vector[7];
    this->symbolTablePathDouble["/instrumentation/encoder/pressure-alt-ft"] = vector[8];
    this->symbolTablePathDouble["/instrumentation/gps/indicated-altitude-ft"] = vector[9];
    this->symbolTablePathDouble["/instrumentation/gps/indicated-ground-speed-kt"] = vector[10];
    this->symbolTablePathDouble["/instrumentation/gps/indicated-vertical-speed"] = vector[11];
    this->symbolTablePathDouble["/instrumentation/heading-indicator/indicated-heading-deg"] = vector[12];
    this->symbolTablePathDouble["/instrumentation/magnetic-compass/indicated-heading-deg"] = vector[13];
    this->symbolTablePathDouble["/instrumentation/slip-skid-ball/indicated-slip-skid"] = vector[14];
    this->symbolTablePathDouble["/instrumentation/turn-indicator/indicated-turn-rate"] = vector[15];
    this->symbolTablePathDouble["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = vector[16];
    this->symbolTablePathDouble["/controls/flight/rudder"] = vector[17];
    this->symbolTablePathDouble["/controls/flight/flaps"] = vector[18];
    this->symbolTablePathDouble["/controls/engines/current-engine/throttle"] = vector[19];
    this->symbolTablePathDouble["/engines/engine/rpm"] = vector[20];
    this->symbolTablePathDouble["/controls/flight/aileron"] = vector[21];
    this->symbolTablePathDouble["/controls/flight/elevator"] = vector[22];
}

void PlaneData::setIp_address(const string &ip_address) {
    PlaneData::ip_address = ip_address;
}

void PlaneData::setPort(int port) {
    PlaneData::port = port;
}

string PlaneData::FixThePath(string toBeFixed){
    //"set controls/flight/rudder 0\r\n"
    string path = toBeFixed;
    if(path[0]=='/'){
        path.erase(0,1);
    }
    string first = "set ";

    first.append(path);
    first.append("\r\n");
    return first;

}

void PlaneData::openSocket(string ip, double portNumber) {
    int portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    portno = portNumber;
    /* Create a socket point */
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    server = gethostbyname(ip.c_str());
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
}

void PlaneData::writeToSimulator(const char *buffer) {
    int n;
    string toBeFixed(buffer);
    toBeFixed = FixThePath(toBeFixed);
    /* Send message to the server */
    n = write(sockfd, toBeFixed.c_str(), toBeFixed.length());
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}

//void PlaneData::SetValueInGame(string pathAndNewValue){
//    pathAndNewValue = FixThePath(pathAndNewValue);
//    int sockfd, portno, n;
//    struct sockaddr_in serv_addr;
//    struct hostent *server;
//    portno = this->port;
//    /* Create a socket point */
//    sockfd = socket(AF_INET, SOCK_STREAM, 0);
//    if (sockfd < 0) {
//        throw("ERROR opening socket");
//    }
//
//    server = gethostbyname(this->ip_address.c_str());
//
//    if (server == NULL) {
//        fprintf(stderr,"ERROR, no such host\n");
//        exit(0);
//    }
//
//    bzero((char *) &serv_addr, sizeof(serv_addr));
//    serv_addr.sin_family = AF_INET;
//    bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
//    serv_addr.sin_port = htons((uint16_t)portno);
//
//    /* Now connect to the server */
//    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
//        throw "ERROR connecting";
//    }
//// "set controls/flight/rudder 0\r\n"
//    n = write(sockfd, pathAndNewValue.c_str(), pathAndNewValue.length());
//    if (n < 0) {
//        throw("ERROR writing to socket");
//    }
//}