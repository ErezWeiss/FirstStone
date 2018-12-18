//
// Created by erez on 12/18/18.
//

#include "Minus.h"

double Minus::calculate() const{
    return this->left->calculate() - this->right->calculate();
}