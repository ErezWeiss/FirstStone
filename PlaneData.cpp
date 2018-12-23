//
// Created by erez on 12/22/18.
//

#include <sstream>
#include <vector>
#include "PlaneData.h"

PlaneData::PlaneData() {

}
double PlaneData::getValueByName(string str){
    map<string, int>::iterator it;
    fot(it= this->symbolTableNameDouble.begin();it!=this->symbolTableNameDouble.end;++it)
    {
        if(it->first==str) {
            it->second;
        }
    }
    //should throw exception here couse there is no value for that parameter
    return 0;



double PlaneData::getValueByName(string str){
    return this->symbolTableNameDouble.find(str)->second;
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
    this->symbolTablePathDouble["/controls/engines/engine/throttle"] = vector[19];
    this->symbolTablePathDouble["/engines/engine/rpm"] = vector[20];
    this->symbolTablePathDouble["/controls/flight/aileron"] = vector[21];
    this->symbolTablePathDouble["/controls/flight/elevator"] = vector[22];
}