//
// Created by user on 12/19/2018.
//
#include "Shunting.h"
#include "Number.h"
#include "Mul.h"
#include "Div.h"
#include "Minus.h"
#include "Plus.h"
#include <bits/stdc++.h>


Shunting::Shunting(PlaneData *planeData) {
    this->planeData = planeData;
    initializeMap();
}

void Shunting::initializeMap() {
//    this->prcedence.insert(pair<char, int>('/', 2));
//    this->prcedence.insert(pair<char, int>('*', 2));
//    this->prcedence.insert(pair<char, int>('+', 1));
//    this->prcedence.insert(pair<char, int>('-', 1));
//    this->prcedence.insert(pair<char, int>(')', 0));
//    this->prcedence.insert(pair<char, int>('(', 0));
}

int Shunting::precedence(char operation) {
    if (this->op_dictionary.count(operation)) {
        return this->op_dictionary.at(operation);
    }
    throw "invalid operation!";
}

int Shunting::operationPriority(char operation) {
    if (operation == '*' || operation == '/') {
        return 2;
    } else if (operation == '+' || operation == '-') {
        return 1;
    } else {
        return 0;
    }
}

Expression *Shunting::applyOp(Expression *val1, Expression *val2, char operation) {
    switch (operation) {
        case '*':
            return new Mul(val1, val2);
        case '/':
            return new Div(val1, val2);
        case '+':
            return new Plus(val1, val2);
        case '-':
            return new Minus(val1, val2);
        default:
            break;
    }
}

//bool *Shunting::isParam(string tokens) {
//    map<string, int>::iterator it;
//    fot(it=this->symbolTableNameDouble.begin();it!=this->symbolTableNameDouble.end;++it)
//    {
//        if(it->first==tokens) {
//            return true;
//        }
//    }
//    return false;
//}
// Function that returns value of
// expression after evaluation.
Expression *Shunting::createExpression(string tokens) {
    //int i;
    // stack to store integer values.
    stack<Expression *> value;
    // stack to store operators.
    stack<char> operators;
    for (int i = 0; i < tokens.length(); i++) {
        // Current token is a whitespace,
        // skip it.
        if (tokens[i] == ' ')
            continue;
            // Current token is an opening
            // brace, push it to 'ops'
        else if (tokens[i] == '(') {
            operators.push(tokens[i]);
        }
            // Current token is a number, push
            // it to stack for numbers.
//        else if (isdigit(tokens[i])) {
//            int val = 0;
//            // There may be more than one
//            // digits in number.
//            while (i < tokens.length() &&
//                   isdigit(tokens[i])) {
//                val = (val * 10) + (tokens[i] - '0');
//                i++;
//            }
//            i--;
//            Expression *num = new Number(val);
//            value.push(num);
//        }
        else if (isdigit(tokens[i])) {
            //will hold the current number which is consists of the current chars.
            double temp = 0;
            double tempDecimal = 0;
            int exponent = 1;
//        minusOp = true;
            //turns a string that consists of numbers into an integer.
            while (i < tokens.length() && isdigit(tokens[i])) {
                temp *= 10;
                temp += (tokens[i] - '0');
                i++;
            }
            if (i < tokens.length() && tokens[i] == '.') {
                i++;
                while (i < tokens.length() && isdigit(tokens[i])) {
                    tempDecimal += ((double) (tokens[i] - '0') /
                                    pow(10, exponent));
                    exponent++;
                    i++;
                }
                temp += tempDecimal;
            }
            i--;
            //push the number to the numbers' stack
            value.push(new Number(temp));
            //ניסיון להמיר משתנים לערכם
//        else if (isParam(tokens[i])) {
//            Expression *num = new Number((symbolTableNameDouble[tokens[i]]));
//            value.push(num);
//        }
            // Closing brace encountered, solve
            // entire brace.
        } else if (tokens[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                Expression *val2 = value.top();
                value.pop();
                Expression *val1 = value.top();
                value.pop();
                char op = operators.top();
                operators.pop();
                value.push(applyOp(val1, val2, op));
            }
            // pop opening brace.
            operators.pop();
        }

            // Current token is an operator.
        else if (tokens[i] == '+' || tokens[i] == '-' || tokens[i] == '*' || tokens[i] == '/') {
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while (!operators.empty() && precedence(operators.top())
                                         >= precedence(tokens[i])) {
                Expression *val2 = value.top();
                value.pop();

                Expression *val1 = value.top();
                value.pop();

                char op = operators.top();
                operators.pop();

                value.push(applyOp(val1, val2, op));
            }
            // Push current token to 'ops'.
            operators.push(tokens[i]);
        } else {
            string variableName = "";
//            minusOp = true;
            while (operationPriority(tokens[i]) == 0 && i < tokens.length()) {
                if (tokens[i] != ' ') {
                    variableName += tokens[i];
                }
                i += 1;
            }
            Expression *variableValue = new Number(this->planeData->getValueByName(variableName));
            value.push(variableValue);
            i -= 1;
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while (!operators.empty()) {
        Expression *val2 = value.top();
        value.pop();
        Expression *val1 = value.top();
        value.pop();
        char op = operators.top();
        operators.pop();
        value.push(applyOp(val1, val2, op));
    }

    // Top of 'values' contains result, return it.
    return value.top();
}
