#include <iostream>
#include "Number.h"
#include "Div.h"
#include "Lexer.h"
#include "Shunting.h"

int main(int argc, char* argv[]) {
//    string file = argv[1];
//    Lexer *lexer = new Lexer(file);
//    vector<string> commands = lexer->getStringVector();
//    cout << "hi";
Shunting shunting;
    Expression* ex1=shunting.createExpression("5 + 3");
    Expression* ex2=shunting.createExpression("(5+ 3)* (7-4)/  6");
    cout<<ex2->calculate()<<endl;
}