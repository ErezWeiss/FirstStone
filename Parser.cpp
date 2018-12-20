//
// Created by erez on 12/18/18.
//

#include <regex>
#include "Parser.h"
#include "OpenServerCommand.h"
#include "CommandExpression.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"

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

/////////////////////////////////////////////ODSInterpret/////////////////////////////////////////////////////
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
/////////////////////////////////////////////ConnectInterpret/////////////////////////////////////////////////////
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
/////////////////////////////////////////////VarInterpret/////////////////////////////////////////////////////
vector<string> Parser::VarInterpret(string line){
    vector<string> returnStringVector;
    string firstWord = line.substr(0, line.find(' '));
    returnStringVector.push_back(firstWord);								// push the first word into the vector
    line.erase(0, line.find(' ') + 1);                                      // erase the first word

    string varName = line.substr(0, line.find('='));
    // erase possible space
    if (varName[varName.length()-1]==' '){
        varName = varName.erase(varName.length()-1, varName.length());
    }
    returnStringVector.push_back(varName);								// push the varName into the vector
    line.erase(0, line.find('=') + 1);                                      // erase the varName

    // erase possible space
    if (line[0]==' '){
        line = line.erase(0, 1);
    }

    // looking for "bind"
    std::size_t found = line.find("bind");
    if (found!=std::string::npos){ // if found!!
        returnStringVector.push_back("bind");                   // push "bind"
        line.erase(0, line.find(' ') + 1);
        returnStringVector.push_back(line);
    } else {
        returnStringVector.push_back(line);
    }
    return returnStringVector;
}
/////////////////////////////////////////////SleepInterpret/////////////////////////////////////////////////////
vector<string> Parser::SleepInterpret(string line){
    vector<string> returnStringVector;
    string firstWord = line.substr(0, line.find(' '));
    returnStringVector.push_back(firstWord);								// push the first word into the vector
    line.erase(0, line.find(' ') + 1);                                      // erase the first word
    returnStringVector.push_back(line);
    return returnStringVector;
}
/////////////////////////////////////////////PrintInterpret/////////////////////////////////////////////////////
vector<string> Parser::PrintInterpret(string line){
    vector<string> returnStringVector;
    string firstWord = line.substr(0, line.find(' '));
    returnStringVector.push_back(firstWord);								// push the first word into the vector
    line.erase(0, line.find(' ') + 1);                                      // erase the first word
    returnStringVector.push_back(line);
    return returnStringVector;
}
/////////////////////////////////////////////WhileInterpret/////////////////////////////////////////////////////

vector<string> Parser::IfWhileInterpret(vector<string> lines){
    string firstLine = lines[0];
    vector<string> returnStringVector;
    string firstWord = firstLine.substr(0, firstLine.find(' '));
    returnStringVector.push_back(firstWord);								// push the first word into the vector
    firstLine.erase(0, firstLine.find(' ') + 1);                                      // erase the first word
    regex b("[<>]=?|==");
    smatch m;
    regex_search (firstLine, m, b);                                         // find the > < >= ....etc....
    string leftCond = firstLine.substr(0,m.position(0));
    if (leftCond[leftCond.length()-1]==' '){
        leftCond = leftCond.substr(0,leftCond.length()-1);
    }
    returnStringVector.push_back(leftCond);                         // push left condition
    returnStringVector.push_back(m[0]);                            // push the operator
    string rightCond = firstLine.substr(m.position(0)+1, firstLine.length());
    if (rightCond[rightCond.length()-1]=='{'){
        rightCond = rightCond.substr(0,rightCond.length()-1);
    }
    returnStringVector.push_back(rightCond);                        // push right condition
    for (auto it = strings.begin()+1; it != strings.end(); ++it){
        returnStringVector.push_back(*it);                          // push all the commands in the line...
    }
    unsigned long length = returnStringVector.size();               // erase the "}"
    if (returnStringVector[length-1]=="}") {
        returnStringVector.erase(returnStringVector.end()-1);
    } else {
        string lastLine = *(returnStringVector.end()-1);
        lastLine = lastLine.substr(0, lastLine.length()-1);
        returnStringVector.erase(returnStringVector.end()-1);
        returnStringVector.push_back(lastLine);
    }
    return returnStringVector;
}



/////////////////////////////////////////////EqualInterpret/////////////////////////////////////////////////////
vector<string> Parser::EqualInterpret(string line){

}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////START INTERPRET/////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
void Parser::startInterpret() {
    string bufferedLine;
    vector<string> returnStringVector;
    for (auto it = strings.begin(); it != strings.end(); ++it) {
        bufferedLine = *it;
        string firstWord = bufferedLine.substr(0, bufferedLine.find(" "));

        if(firstWord=="openDataServer") {
            returnStringVector = ODSInterpret(*it);
        } else if(firstWord=="connect") {
            returnStringVector = ConnectInterpret(*it);
        } else if (firstWord=="var") {
            returnStringVector = VarInterpret(*it);
        }

        else if (firstWord=="while") {
            vector<string> lines;
            while (bufferedLine.find('}')==std::string::npos){  // while the line doesn't contains '}'
                lines.push_back(bufferedLine);
                it++;
                bufferedLine = *it;
            }
            lines.push_back(bufferedLine);
            returnStringVector = IfWhileInterpret(lines);
        }

        else if (firstWord=="if") {
            // some det
        } else if (firstWord=="print") {
            returnStringVector = PrintInterpret(*it);
        } else if (firstWord=="sleep") {
            returnStringVector = SleepInterpret(*it);
        } else {
            EqualInterpret(*it);
        }
    }
}





void Parser::parserTheText(vector<string> strings){
    string str;
    str = strings[0];
    if (str=="var"){
        expressionMap[str]->calculate(strings,symbolTableNamePath,symbolTablePathDouble, symbolTableNameDouble);
    } else {
        expressionMap[str]->calculate(strings);
    }
}
