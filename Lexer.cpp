//
// Created by erez on 12/18/18.
//

#include <fstream>
#include <iostream>
#include "Lexer.h"
Lexer::Lexer(string &file){
    this->file=file;
    this->lexTheStringIntoVector();
}

void Lexer::lexTheStringIntoVector() {
    ifstream file(this->file.c_str());
    if(file.is_open()) {
        string line;
        for (line; getline(file, line);) {

            size_t pos;
            while( ( pos = line.find( "  " ) )!=std::string::npos ) {       // remove duplicate spaces
                line = line.replace(pos, 2, " ");
            }
            this->strings.push_back(line);
        }
    } else {
        throw "open file error!";
    }
}

vector<string> Lexer::getStringVector(){
    return this->strings;
}