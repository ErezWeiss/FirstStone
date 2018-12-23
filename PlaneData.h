//
// Created by erez on 12/22/18.
//

#ifndef FIRSTSTONE_PLANEDATA_H
#define FIRSTSTONE_PLANEDATA_H
#include <map>
#include <string>
using namespace std;

class PlaneData {
private:
    map<string, double> symbolTablePathDouble;  // updated from game by thread
    map<string, string> symbolTableNamePath;    // for bind
    map<string, double> symbolTableNameDouble;  // for us. for the bosses

public:
    PlaneData();
    map<string, string> GetSymbolTableNamePath(){
        return this->symbolTableNamePath;
    }
    map<string, double> GetSymbolTablePathDouble(){
        return this->symbolTablePathDouble;
    }
    map<string, double> GetSymbolTableNameDouble(){
        return this->symbolTableNameDouble;
    }
    double getValueByName(string st);
    void ReadFromPlane(string info);
    void UpdateTheTable(vector<double> vector);
};


#endif //FIRSTSTONE_PLANEDATA_H
