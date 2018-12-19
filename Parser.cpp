//
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

}

void Parser::setTheTables(){
    this->expressionMap.insert(pair<string,Expression*>("openDataServer", new CommandExpression(new OpenServerCommand));
    this->expressionMap.insert(pair<string,Expression*>("connect", new CommandExpression(new ConnectCommand));
    this->expressionMap.insert(pair<string,Expression*>("var", new CommandExpression(new DefineVarCommand));
    this->expressionMap.insert(pair<string,Expression*>("while", new CommandExpression(new WhileCommand));


    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/airspeed-indicator/indicated-speed-kt", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/altimeter/indicated-altitude-ft", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/altimeter/pressure-alt-ft", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-pitch-deg", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-roll-deg", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-pitch-deg", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-roll-deg", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/encoder/indicated-altitude-ft", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/encoder/pressure-alt-ft", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/gps/indicated-altitude-ft", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/gps/indicated-ground-speed-kt", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/gps/indicated-vertical-speed", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/heading-indicator/indicated-heading-deg", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/magnetic-compass/indicated-heading-deg", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/slip-skid-ball/indicated-slip-skid", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/turn-indicator/indicated-turn-rate", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/controls/flight/rudder", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/controls/flight/flaps", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/controls/engines/engine/throttle", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/engines/engine/rpm", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/controls/flight/aileron", 0);
    this->symbolTablePathDouble.insert(pair<string,double>("/controls/flight/elevator", 0);
