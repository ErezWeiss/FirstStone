#include <iostream>
#include "Number.h"
#include "Div.h"

int main() {
    Number* one = new Number(1);
    Number* two = new Number(2);
    Div* plus = new Div(one,two);
    std::cout << one->calculate() << "\n";
    std::cout << two->calculate() << "\n";
    std::cout << plus->calculate() << "\n";
}