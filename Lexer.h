//
// Created by erez on 12/18/18.
//

#ifndef FIRSTSTONE_LEXER_H
#define FIRSTSTONE_LEXER_H
#include <vector>
#include <string>

using namespace std;

class Lexer {
private:
    string file;
    vector<string> strings;
public:
    Lexer(string &file);
    void lexTheStringIntoVector();
    vector<string> getStringVector();
};


#endif //FIRSTSTONE_LEXER_H
