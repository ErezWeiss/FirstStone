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
    vector<string> strings;

public:
    Parser(vector<string> &strings);
};


#endif //FIRSTSTONE_PARSER_H
