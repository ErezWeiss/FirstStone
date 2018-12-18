#include <iostream>
#include "Number.h"
#include "Div.h"
#include "Lexer.h"

int main(int argc, char* argv[]) {
    string file = argv[1];
    Lexer *lexer = new Lexer(file);
    vector<string> commands = lexer->getStringVector();
    cout << "hi";

}