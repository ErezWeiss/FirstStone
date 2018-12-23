//פסודו קוד כיוון טוב
// Created by erez on 12/18/18.
//

#include "ConditionParser.h"

bool ConditionParser::conditionCheck() {
    bool loop= true;
    Shunting shunting(this->planeData);
    int i=0;
    if ((this->str[2]=="<")&&((shunting.createExpression(this->str[1])->calculate())>=(shunting.createExpression(str[2])->calculate()))){
        loop= false;
    }
    if ((this->str[2]==">")&&((shunting.createExpression(this->str[1])->calculate())<=(shunting.createExpression(str[2])->calculate()))){
        loop= false;
    }
    if (((this->str[2]=="=")||(this->str[2]=="=="))&&((shunting.createExpression(this->str[1])->calculate())==(shunting.createExpression(str[2])->calculate()))){
        loop= false;
    }
    if ((this->str[2]=="<=")&&((shunting.createExpression(this->str[1])->calculate())>(shunting.createExpression(str[2])->calculate()))){
        loop= false;
    }
    if ((this->str[2]==">=")&&((shunting.createExpression(this->str[1])->calculate())<(shunting.createExpression(str[2])->calculate()))){
        loop= false;
    }
    return loop;
}


int ConditionParser::execute(){
    Shunting shunting(this->planeData);
    bool loop=conditionCheck();
    while (loop){
        for (int i=4;i<this->str.size();i++){
            shunting.createExpression(this->str[i])->calculate();
        }
    loop=conditionCheck();
    return 0;
    }
}