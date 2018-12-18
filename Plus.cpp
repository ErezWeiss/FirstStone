//
// Created by erez on 12/18/18.
//

#include "Plus.h"

double Plus::calculate() const {
    return this->left->calculate() + this->right->calculate();
}