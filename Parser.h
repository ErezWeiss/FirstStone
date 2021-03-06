//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_PARSER_H
#define FIRSTSTONE_PARSER_H
#include <map>
#include <vector>
#include "Expression.h"
#include "PlaneData.h"
#include "CommandExpression.h"

using namespace std;

class Parser {
private:
    map<string, CommandExpression*> expressionMap;
    vector<string> strings;
    PlaneData* planeData;
    Shunting* shunting;

public:
    Parser(vector<string> &strings);
    void setTheTables();
    void startInterpret();
    vector<string> ODSInterpret(string line);
    vector<string> ConnectInterpret(string line);
    vector<string> VarInterpret(string line);
    vector<string> SleepInterpret(string line);
    vector<string> PrintInterpret(string line);
    vector<string> IfWhileInterpret(vector<string> lines);
    vector<string> IfInterpret(vector<string> lines);
    vector<string> EqualInterpret(string line);
    void DoTheCommands(vector<string> strings);
    ~Parser();
};


#endif //FIRSTSTONE_PARSER_H
