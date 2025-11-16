// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.
#include "calculator.h"
#include <sstream>
#include <cmath>

// Чтение числа из потока ввода.
// Возвращает true, если чтение прошло успешно,
// иначе записывает ошибку в stderr и возвращает false.
bool ReadNumber(Number& result) {
    std::string input;
    std::cin >> input;

    std::stringstream ss(input);
    if (!(ss >> result)) {
        std::cerr << "Error: Numeric operand expected\n";
        return false;
    }
    return true;
}

// Основной цикл работы калькулятора.
// Возвращает true, если выход произошел по команде 'q',
// иначе возвращается false при возникновении ошибки.
bool RunCalculatorCycle() {
    Number memory = 0;// Ячейка памяти изначально пуста
    Number current_number = 0.0; // Текущее значение калькулятора

  //  std::cout << "Enter initial number: ";
    if (!ReadNumber(current_number))
        return false;

    while (true) {
        std::string command;
        std::cin >> command;

        if (command == "q") {
            return true; // Нормальное завершение работы
        } else if (command == ":") {
            if (!ReadNumber(current_number))
                return false;
        } else if (command == "c") {
            current_number = 0.0;
        } else if (command == "=") {
            std::cout << current_number << "\n";
        } else if (command == "+") {
            Number temp;
            if (!ReadNumber(temp))
                return false;
            current_number += temp;
        } else if (command == "-") {
            Number temp;
            if (!ReadNumber(temp))
                return false;
            current_number -= temp;
        } else if (command == "*") {
            Number temp;
            if (!ReadNumber(temp))
                return false;
            current_number *= temp;
        } else if (command == "/") {
            Number temp;
            if (!ReadNumber(temp))
                return false;
            if (temp == 0) {
                //std::cerr << "Error: Division by zero\n";
                //return false;
            }
            current_number /= temp;
        } else if (command == "**") {
            Number temp;
            if (!ReadNumber(temp))
                return false;
            current_number = std::pow(current_number, temp);
        } else if (command == "s") {
            memory = current_number;
        } else if (command == "l") {
            if (std::isnan(memory)) {
                std::cerr << "Error: Memory is empty\n";
                return false;
            }
            current_number = memory;
        } else {
            std::cerr << "Error: Unknown token " << command << "\n";
            return false;
        }
    }
}
