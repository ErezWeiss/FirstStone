}    //
// Created by erez on 12/18/18.
//

#include "Parser.h"
#include "OpenServerCommand.h"
#include "CommandExpression.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "WhileCommand.h"

Parser::Parser(vector<string> &strings){
    this->strings = strings;
    setTheTables();
}
//hey bro
void Parser::setTheTables(){
    this->expressionMap.insert(pair<string,Expression*>("openDataServer", new CommandExpression(new OpenServerCommand())));
    this->expressionMap.insert(pair<string,Expression*>("connect", new CommandExpression(new ConnectCommand())));
    this->expressionMap.insert(pair<string,Expression*>("var", new CommandExpression(new DefineVarCommand())));
    this->expressionMap.insert(pair<string,Expression*>("while", new CommandExpression(new WhileCommand())));


    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/airspeed-indicator/indicated-speed-kt", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/altimeter/indicated-altitude-ft", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/altimeter/pressure-alt-ft", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-pitch-deg", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-roll-deg", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-pitch-deg", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-roll-deg", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/encoder/indicated-altitude-ft", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/encoder/pressure-alt-ft", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/gps/indicated-altitude-ft", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/gps/indicated-ground-speed-kt", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/gps/indicated-vertical-speed", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/heading-indicator/indicated-heading-deg", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/magnetic-compass/indicated-heading-deg", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/slip-skid-ball/indicated-slip-skid", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/turn-indicator/indicated-turn-rate", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/controls/flight/rudder", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/controls/flight/flaps", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/controls/engines/engine/throttle", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/engines/engine/rpm", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/controls/flight/aileron", 0));
    this->symbolTablePathDouble.insert(pair<string,double>("/controls/flight/elevator", 0));
}


void Parser::startInterpret() {
    string bufferedLine;
    for (auto it = strings.begin(); it != strings.end(); ++it) {
        bufferedLine = *it;
        string firstWord = bufferedLine.substr(0, bufferedLine.find(" "));
        switch (firstWord) {
            case "openDataServer":
                vector<string> returnStringVector = ODSInterpret(*it);
            case "connect":
                vector<string> returnStringVector = ConnectInterpret(*it);
                // parsethetext(returnStringVector);
            case "var":
                VarInterpret(*it);
            case while:
                // put attention! increase the t to be the end of the '}' note
            case "print":
                PrintInterpret(*it);
            case "sleep":
                SleepInterpret(*it);
            default:
                EqualInterpret(*it)
        }
    }
}

vector<string> Parser::ODSInterpret(string line) {
    vector<string> returnStringVector;
    string firstWord = line.substr(0, line.find(" "));
    returnStringVector.push_back(firstWord);                                // push the first word into the vector
    line.erase(0, line.find(' ') + 1);                                      // erase the first word
    string port = "";
    for (unsigned int i = 0; i < line.length(); i++) {                      // if it an complicated exp. cut it and put into the vector
        char c = line[i];
        if (isdigit(c)) {
            if (line[i+1]==' ' && isdigit(line[i + 2])) {
                port = line.substr(0, i+1);
                returnStringVector.push_back(port);
                line.erase(0, i + 2);
            }
        }
    }
    returnStringVector.push_back(line);
    return returnStringVector;
}

vector<string> Parser::ConnectInterpret(string line){
    vector<string> returnStringVector;
    string firstWord = line.substr(0, line.find(" "));
    returnStringVector.push_back(firstWord);								// push the first word into the vector
    line.erase(0, line.find(' ') + 1);                                      // erase the first word
    string IP = line.substr(0, line.find(" "));
    returnStringVector.push_back(firstWord);                                // push the IP into vector
    returnStringVector.push_back(line);                                     // push the port
    return returnStringVector;
}
vector<string> Parser::SleepInterpret(string line){}
vector<string> Parser::whileInterpret(string line){}
vector<string> Parser::IfInterpret(string line){}
vector<string> Parser::VarInterpret(string line){}
vector<string> Parser::EqualInterpret(string line){}
vector<string> Parser::PrintInterpret(string line){}


void Parser::parserTheText(vector<string> strings){
    string str;
    str = strings[0];
    if (str=="while"){

    } else {
        expressionMap[str].execute(strings);
    }
}
