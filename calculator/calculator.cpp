#include <cmath>
#include <string>
#include <iostream>
using Number = double;

bool ReadNumber(Number& result){
    if (std::cin >> result) {
        return true;
    }
    else{
        std::cerr<<"Error: Numeric operand expected"<<std::endl;
        return false;
    }
}

bool RunCalculatorCycle(){
    Number number;
    Number Sum = 0;
    Number Save_amount = 0;
    bool has_memory = false;
    std::string operation;
    
    if (!ReadNumber(number)) {
        return false;
    } else {
        for(; ;){

            if(std::cin>>operation){

                if(operation == "+" || operation == "-" || operation == "/" || operation == "*" || operation == "**" || operation == "=" || operation == "q" || operation == ":" || operation == "c" || operation == "s" || operation == "l"){

                    // Условия для дополнительных функций калькулятора.
                    if(operation == "="){
                        std::cout<<Sum<<std::endl;
                        continue;
                    }
                    else if(operation == ":"){
                        if(!ReadNumber(number)){
                            return false;
                        }else{
                            Sum = 0;
                            continue;
                        }
                        
                    }
                    else if(operation == "c"){
                        Sum = 0;
                        number = 0;
                        continue;
                    }
                    else if(operation == "s"){
                        Save_amount = Sum;
                        number = Save_amount;
                        Sum = 0;
                        has_memory = true;
                        continue;
                    }
                    else if(operation == "l"){
                        if(has_memory == true){
                            Sum = Save_amount;
                            number = Save_amount;
                            continue;
                        }else{
                            std::cerr<<"Error: Memory is empty"<<std::endl;
                            break;
                        }
                    }
                    else if(operation == "q"){
                            break;
                    }
                    if(operation == "="){
                        break;
                    }

                    // Ввод 2-го значения.
                    Number second_num;
                    if(!ReadNumber(second_num)){
                            return false;
                    }

                    // Условия операторов.
                    if(operation == "+"){
                        number += second_num;
                        Sum = number;
                        continue;
                    }
                    else if(operation == "-"){
                        number -= second_num;
                        Sum = number;
                        continue;
                    }
                    else if(operation == "*"){
                        number *= second_num;
                        Sum = number;
                        continue;
                    }
                    else if(operation == "/"){
                        number /= second_num;
                        Sum = number;
                        continue;
                    }
                    else if(operation == "**"){
                        number = std::pow(number, second_num);
                        Sum = number;
                        continue;
                    }
                    else if(operation == "q"){
                        break;
                    }
                }
                else{
                    std::cerr<<"Error: Unknown token "<<operation<<std::endl;
                    break;
                }
            }
            else{
                    std::cerr<<"Error: Unknown token "<<operation<<std::endl;
                    return false;
                }
        }
        return true;
    }

}
