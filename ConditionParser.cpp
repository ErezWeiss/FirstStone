//פסודו קוד כיוון טוב
// Created by erez on 12/18/18.
//

#include <iostream>
#include "ConditionParser.h"

bool ConditionParser::conditionCheck() {
    bool loop= true;

    // if condition
    if (this->params[0]=="if"){
        loop=false;
        return loop;
    }

    int i=0;
    if ((this->params[2]=="<")&&((shunting->createExpression(this->params[1])->calculate()) >= (shunting->createExpression(params[3])->calculate()))){
        loop= false;
    }
    if ((this->params[2]==">")&&((shunting->createExpression(this->params[1])->calculate()) <= (shunting->createExpression(params[3])->calculate()))){
        loop= false;
    }
    if (((this->params[2]=="=")||(this->params[2]=="=="))&&((shunting->createExpression(this->params[1])->calculate())==(shunting->createExpression(params[3])->calculate()))){
        loop= false;
    }
    if ((this->params[2]=="<=")&&((shunting->createExpression(this->params[1])->calculate()) > (shunting->createExpression(params[3])->calculate()))){
        loop= false;
    }
    if ((this->params[2]==">=")&&((shunting->createExpression(this->params[1])->calculate()) < (shunting->createExpression(params[2])->calculate()))){
        loop= false;
    }
    return loop;
}


int ConditionParser::execute(){
    Shunting shunting(this->planeData);
    vector<string> returnStringVector;
    bool loop=conditionCheck();
    while (loop){
        for (int i=4;i<this->params.size();i++){
            string firstWord = params[i].substr(0, params[i].find(" "));
            if (firstWord=="print") {
                returnStringVector = this->parser->PrintInterpret(params[i]);
                this->parser->DoTheCommands(returnStringVector);
            } else if (firstWord=="sleep") {
                returnStringVector = this->parser->SleepInterpret(params[i]);
                this->parser->DoTheCommands(returnStringVector);
            } else {
                returnStringVector = this->parser->EqualInterpret(params[i]);
                this->parser->DoTheCommands(returnStringVector);
            }
        }
    loop=conditionCheck();
    }
}

void ConditionParser::setParser(Parser *parser) {
    ConditionParser::parser = parser;
}

void ConditionParser::setExpressionMap(const map<string, CommandExpression *> &expressionMap) {
    ConditionParser::expressionMap = expressionMap;
}
