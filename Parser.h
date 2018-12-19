//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_PARSER_H
#define FIRSTSTONE_PARSER_H
#include <map>
#include <vector>
#include "Expression.h"

using namespace std;

class Parser {
private:
    map<string, Expression*> expressionMap;
    map<string, double> symbolTablePathDouble;
    map<string, string> symbolTableNamePath;
    map<string, double> symbolTableNameDouble;
    vector<string> strings;

public:
    Parser(vector<string> &strings);
    void setTheTables();
};


#endif //FIRSTSTONE_PARSER_H
