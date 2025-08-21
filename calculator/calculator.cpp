#include "calculator.h"
#include <iostream>
#include <cmath>
#include <string>

static Number memory;
static bool memory_initialized = false;

bool ReadNumber(Number& result) {
    if (!(std::cin >> result)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {
    Number number;
    if (!ReadNumber(number)) {
        return false;
    }
    
    std::string command;
    while (std::cin >> command) {
        if (command == "+") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            number += operand;
        }
        else if (command == "-") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            number -= operand;
        }
        else if (command == "*") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            number *= operand;
        }
        else if (command == "/") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            number /= operand;
        }
        else if (command == "**") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            number = std::pow(number, operand);
        }
        else if (command == ":") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            number = operand;
        }
        else if (command == "c") {
            number = 0;
        }
        else if (command == "=") {
            std::cout << number << std::endl;
        }
        else if (command == "q") {
            return true;
        }
        else if (command == "s") {
            memory = number;
            memory_initialized = true;
        }
        else if (command == "l") {
            if (!memory_initialized) {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
            number = memory;
        }
        else {
            std::cerr << "Error: Unknown token " << command << std::endl;
            return false;
        }
    }
    
    return true;
}
