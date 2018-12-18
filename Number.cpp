//
// Created by erez on 12/18/18.
//

#include "Number.h"

Number::Number(double num){
    this->num=num;
}
double Number::calculate() const{
    return this->num;
}
