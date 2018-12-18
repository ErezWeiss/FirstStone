//
// Created by erez on 12/18/18.
//

#include "Mul.h"

double Mul::calculate() const{
    return this->left->calculate() * this->right->calculate();
}