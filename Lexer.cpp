//
// Created by erez on 12/18/18.
//

#include <fstream>
#include "Lexer.h"
Lexer::Lexer(string &file){
    this->file=file;
    this->lexTheStringIntoVector();
}

void Lexer::lexTheStringIntoVector(){
    ifstream file(this->file.c_str());
    if(file.is_open()) {
        string word;
        while (file >> word) {
            this->strings.push_back(word);
        }
    } else {
        throw "open file error!";
    }
}

vector<string> Lexer::getStringVector(){
    return this->strings;
}