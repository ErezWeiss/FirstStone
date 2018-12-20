//
// Created by user on 12/19/2018.
//
#include "Shunting.h"
#include "Number.h"
#include "Mul.h"
#include "Div.h"
#include "Minus.h"
#include "Plus.h"

Shunting::Shunting() {
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

// Function that returns value of
// expression after evaluation.
Expression *Shunting::createExpression(string tokens) {
    //int i;
    // stack to store integer values.
    stack<Expression*> value;
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
        else if (isdigit(tokens[i])) {
            int val = 0;
            // There may be more than one
            // digits in number.
            while (i < tokens.length() &&
                   isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            i--;
            Expression *num = new Number(val);
            value.push(num);
        }
            // Closing brace encountered, solve
            // entire brace.
        else if (tokens[i] == ')') {
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
        else {
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