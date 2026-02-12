#include "calculator.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <format>
#include <cmath>

using Number = double;

const std::vector<std::string> OPERATIONS = { "q", "=", ":", "+", "-", "*", "/", "**", "s", "l", "c" };

//тип данных
enum DataType {
    //число
    NUMBER,
    //операция
    OPERATION
};

bool ReadNumber(Number& result);
bool ReadOperation(int& index);
int FindIndex(const std::vector<std::string>& vec, std::string& value);
bool CalcOrExit(const Number& x, const int& op, Number& result);

// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.
void RunCalculatorCycle(){
    
    DataType type = DataType::NUMBER;
    bool was_error = false;
    //bool isfirst = true;
    Number result = 0;
    Number x = 0;
    bool ismemory = false;
    Number memory = 0;
    int i_op = 2;
    while(!was_error){
        switch(type){
            case DataType::NUMBER:{
                was_error = !ReadNumber(x);
                was_error = was_error || CalcOrExit(x, i_op, result);
                type = DataType::OPERATION;
            }break;
            case DataType::OPERATION:{
                was_error = !ReadOperation(i_op);
                switch(i_op){
                    case 0:{
                        was_error = true;
                        return;
                    }
                    case 1:{
                        std::cout << result << std::endl;
                        type = DataType::OPERATION;
                    }break;
                    case 8:{
                        memory = result;
                        ismemory = true;
                    }break;
                    case 9:{
                        if (ismemory){
                            result = memory;
                        }else{
                            was_error = true;
                            std::cerr << "Error: Memory is empty" << std::endl;
                        }
                    }break;
                    case 10:{
                        result = 0;
                    }break;
                    default:{
                        type = DataType::NUMBER;
                    }break;
                }
            }break;
        }
    }
}

bool ReadNumber(Number& result){
    if (std::cin >> result){
        return true;
    }else{
        std::cerr << "Error: Numeric operand expected" << std::endl;
        result = 0;
        return false;
    }
}

bool ReadOperation(int& index){
    std::string op;
    std::cin >> op;
    index = FindIndex(OPERATIONS, op);
    if (index == -1){
        std::cerr << std::format("Error: Unknown token {}", op) << std::endl;
    }
    return index != -1;
}

int FindIndex(const std::vector<std::string>& vec, std::string& value){
    for(std::size_t i = 0; i < vec.size(); ++i){
        if (vec[i] == value){
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool CalcOrExit(const Number& x, const int& op, Number& result){
    switch(op){
        case 0:{
            return true;
        }
        case 1:{
        }break;
        case 2:{
            result = x;
        }break;
        case 3:{
            result += x;
        }break;
        case 4:{
            result -= x;
        }break;
        case 5:{
            result *= x;
        }break;
        case 6:{
            result /= x;
        }break;
        case 7:{
            result = std::pow(result, x);
        }break;
    }    
    return false;
}
