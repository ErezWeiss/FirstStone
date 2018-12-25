#include <iostream>
#include "Number.h"
#include "Div.h"
#include "Lexer.h"
#include "Shunting.h"
#include "Parser.h"
bool connectedGame = false;

int main(int argc, char* argv[]) {
    string filename = argv[1];
    Lexer lexer(filename);
    vector<string> vector = lexer.getStringVector();
    Parser parser(vector);
    parser.startInterpret();
while(1){}
    return 0;
//PlaneData *planeData = new PlaneData();
//Shunting shunting(planeData);
////planeData->AddToSymbolTableNameDouble("header",5);
//planeData->AddToSymbolTableNamePath("b","c");
//planeData->AddToSymbolTablePathDouble("c",10);
////Expression * ex3 =new Number(shunting.createExpression("b/2+3")->calculate());
////Expression * ex =new Number(shunting.createExpression("header/2+3")->calculate());
//    Expression * ex1 =shunting.createExpression("b/2+3");
//    cout << ex1->calculate();
}