//
// Created by erez on 12/18/18.
//

#include "Div.h"

double Div::calculate() const{
    return this->left->calculate() / this->right->calculate();
}