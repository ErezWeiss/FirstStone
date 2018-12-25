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
    string ip_address;
    int port;
public:
    void setIp_address(const string &ip_address);

    void setPort(int port);

public:
    PlaneData();
    string FixThePath(string toBeFixed);
    void SetValueInGame(string pathAndNewValue);
    double getValueByName(string st);
    void ReadFromPlane(string info);
    void UpdateTheTable(vector<double> vector);

    void AddToSymbolTableNamePath(string a, string b);
    void AddToSymbolTablePathDouble(string a, double b);
    void AddToSymbolTableNameDouble(string a, double b);

    map<string, double> getsymbolTablePathDouble(){
        return this->symbolTablePathDouble;
    }
    map<string, string> getSymbolTableNamePath(){
        return this->symbolTableNamePath;
    }
    map<string, double> getSymbolTableNameDouble(){
        return this->symbolTableNameDouble;
    }

};


#endif //FIRSTSTONE_PLANEDATA_H
