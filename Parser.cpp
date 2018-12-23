//
// Created by erez on 12/18/18.
//

#include <regex>
#include "Parser.h"
#include "OpenServerCommand.h"
#include "CommandExpression.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "SleepCommand.h"
#include "ConditionParser.h"
#include "EqualCommand.h"
#include "PrintCommand.h"

Parser::Parser(vector<string> &strings){
    this->planeData = new PlaneData;
    this->strings = strings;
    setTheTables();
}
//hey bro
void Parser::setTheTables(){
    OpenServerCommand* openServerCommand = new OpenServerCommand();
    openServerCommand->setPlaneData(this->planeData);
    this->expressionMap.insert(pair<string,CommandExpression*>("openDataServer", new CommandExpression(openServerCommand)));
    ConnectCommand* connectCommand = new ConnectCommand();
    connectCommand->setPlaneData(this->planeData);
    this->expressionMap.insert(pair<string,CommandExpression*>("connect", new CommandExpression(connectCommand)));
    DefineVarCommand* defineVarCommand = new DefineVarCommand();
    defineVarCommand->setPlaneData(this->planeData);
    this->expressionMap.insert(pair<string,CommandExpression*>("var", new CommandExpression(defineVarCommand)));
    EqualCommand* equalCommand = new EqualCommand();
    equalCommand->setPlaneData(this->planeData);
    this->expressionMap.insert(pair<string,CommandExpression*>("=", new CommandExpression(equalCommand)));
    ConditionParser* conditionParser= new ConditionParser();
    conditionParser->setPlaneData(this->planeData);
    this->expressionMap.insert(pair<string,CommandExpression*>("while", new CommandExpression(conditionParser)));
    SleepCommand* sleepCommand= new SleepCommand();
    sleepCommand->setPlaneData(this->planeData);
    this->expressionMap.insert(pair<string,CommandExpression*>("sleep", new CommandExpression(sleepCommand)));
    PrintCommand* printCommand= new PrintCommand();
    printCommand->setPlaneData(this->planeData);
    this->expressionMap.insert(pair<string,CommandExpression*>("print", new CommandExpression(printCommand)));
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
    vector<string> returnStringVector;
    returnStringVector.push_back("=");

    string firstWord = line.substr(0, line.find("="));
    if (firstWord[firstWord.length()-1]==' '){
        firstWord = firstWord.substr(0,firstWord.length()-1);               // erase spaces
    }
    returnStringVector.push_back(firstWord);								// push the first word into the vector
    line.erase(0, line.find('=') + 1);                                      // erase the first word

    if (line[0]==' '){
        line = firstWord.substr(1,firstWord.length()-1);               // erase spaces
    }
    returnStringVector.push_back(line);                                     // push the port
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
            returnStringVector = EqualInterpret(*it);
        }
    }
}


void Parser::DoTheCommands(vector<string> strings){
    string str;
    str = strings[0];
    expressionMap[str] -> SetParams(strings);
    expressionMap[str] -> calculate();
}
