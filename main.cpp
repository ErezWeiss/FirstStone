#include <iostream>
#include "Number.h"
#include "Div.h"
#include "Lexer.h"
#include "Shunting.h"
#include "Parser.h"

int main(int argc, char* argv[]) {
    string filename = argv[1];
    Lexer lexer(filename);
    lexer.lexTheStringIntoVector();
    vector<string> vector = lexer.getStringVector();
    Parser parser(vector);
    parser.startInterpret();
}