// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.
#include "calculator.h"

#include <cmath>
#include <iostream>
#include <string>

bool ReadNumber(Number& result) {
    if (!(std::cin >> result)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {
    Number currentNumber;
    if (!ReadNumber(currentNumber)) {
        return false;
    }

    Number memoryCell = 0;
    bool isMemorySaved = false;

    std::string operation;
    while (std::cin >> operation) {
        if (operation == ":") {
            if (!ReadNumber(currentNumber)) {
                return false;
            }
        } else if (operation == "+") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            currentNumber += operand;
        } else if (operation == "-") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            currentNumber -= operand;
        } else if (operation == "*") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            currentNumber *= operand;
        } else if (operation == "/") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            currentNumber /= operand;
        } else if (operation == "**") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            currentNumber = std::pow(currentNumber, operand);
        } else if (operation == "=") {
            std::cout << currentNumber << std::endl;
        } else if (operation == "s") {
            memoryCell = currentNumber;
            isMemorySaved = true;
        } else if (operation == "l") {
            if (!isMemorySaved) {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
            currentNumber = memoryCell;
        } else if (operation == "q") {
            return true;
        } else if (operation == "c") {
            currentNumber = 0;
        } else {
            std::cerr << "Error: Unknown token " << operation << std::endl;
            return false;
        }
    }
    return false;
}
