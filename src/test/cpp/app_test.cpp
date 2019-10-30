#include "app.h"
#include <cassert>
#include <iostream>

int main() {

    AdventOfCode2016::Answers greeter;

    std::cout << "01-01: " << greeter._01_01() << std::endl;
    std::cout << "01-02: " << greeter._01_02() << std::endl;
    std::cout << "02-01: " << greeter._02_01() << std::endl;
    std::cout << "02-02: " << greeter._02_02() << std::endl;
    std::cout << "03-01: " << greeter._03_01() << std::endl;

    return 0;

}
