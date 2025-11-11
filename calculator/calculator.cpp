#include "calculator.h"
#include <iostream>
#include <cmath>
#include <string>

bool ReadNumber(Number& result) {
    std::cin >> result;
    if (std::cin.fail()) {
        std::cin.clear();
        std::string token;
        std::cin >> token;
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {
    Number current = 0;
    Number memory = 0;
    bool has_memory = false;

    if (!ReadNumber(current)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }

    std::string token;
    while (std::cin >> token) {
        if (token == "+") {
            Number operand;
            if (!ReadNumber(operand)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            current += operand;
        }
        else if (token == "-") {
            Number operand;
            if (!ReadNumber(operand)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            current -= operand;
        }
        else if (token == "*") {
            Number operand;
            if (!ReadNumber(operand)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            current *= operand;
        }
        else if (token == "/") {
            Number operand;
            if (!ReadNumber(operand)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            current /= operand;
        }
        else if (token == "**") {
            Number operand;
            if (!ReadNumber(operand)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            current = std::pow(current, operand);
        }
        else if (token == "=") {
            std::cout << current << std::endl;
        }
        else if (token == ":") {
            Number operand;
            if (!ReadNumber(operand)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            current = operand;
        }
        else if (token == "c") {
            current = 0;
        }
        else if (token == "s") {
            memory = current;
            has_memory = true;
        }
        else if (token == "l") {
            if (!has_memory) {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
            current = memory;
        }
        else if (token == "q") {
            return true;
        }
        else {
            std::cerr << "Error: Unknown token " << token << std::endl;
            return false;
        }
    }

    return false;
}
