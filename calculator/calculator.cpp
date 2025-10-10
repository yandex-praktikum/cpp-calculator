// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.
#include <iostream>
#include <cmath>
#include <string> 
#include "calculator.h"


bool ReadNumber(Number &number ){   
   std::cin >> number; 
   if (std::cin.fail()) {
        std::cin.clear();
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
   } else{
        return true;  
   }    
}



bool ReadOperation(int &oper){
    std::string op;
    std::cin >> op;
    oper=-1;
    if (op == "=")  oper =static_cast<int>(Operations::CALC);
    if (op == "+")  oper =  static_cast<int>(Operations::SUM);
    if (op == "-")  oper = static_cast<int>(Operations::DIFF);
    if (op == "*")  oper = static_cast<int>(Operations::MULT);
    if (op == "/")  oper = static_cast<int>(Operations::DIV);
    if (op == "**")  oper = static_cast<int>(Operations::POW);
    if (op == "s")  oper = static_cast<int>(Operations::MEM);
    if (op == "l")  oper = static_cast<int>(Operations::LOAD);
    if (op == "q")  oper = static_cast<int>(Operations::QUIT);
    if (op == ":")  oper = static_cast<int>(Operations::SET);
    if (op == "c")  oper = static_cast<int>(Operations::CLEAR);
    if (oper==-1) {
        std::cerr << "Error: Unknown token " << op << std::endl;
        std::cerr.clear();
        return false;
        } else{
        return true; 
        }
           
    }

bool RunCalculatorCycle(){

    Number cur_sum = 0,left,right,mem=0;
    bool set_mem=false;    
    int oper;
    Operations operation;
    bool status =true;
    bool flag_inf=false; // Flag Infinity number division by zero
 
    if(!ReadNumber(left))   status = false;        

    while (status) {
    if(!ReadOperation(oper)) {
        status = false;
        continue;
    }  

    operation = static_cast<Operations>(oper);

    switch(operation){   
        case Operations::QUIT:
            status = false;
            continue;
        break;
        case Operations::CALC:
            if(flag_inf){
                std::cout << "inf" << std::endl;
                cur_sum=0;
                left=0;
                right=0;
                continue;
            } else{
                cur_sum=left;
                std::cout << cur_sum << std::endl;        
                continue;
            }   
        break;
        case Operations::CLEAR:
             left = 0;        
            if(flag_inf) flag_inf=false;
            continue;
        break;
        case Operations::MEM:
            set_mem=true;
            mem=left;           
            continue;
        break;
        case Operations::LOAD:
            if(set_mem){
                 left=mem;             
             } else{
                std::cerr  << "Error: Memory is empty" << std::endl;
                return false;
            }
           continue;
        break;
        default:
           if(!ReadNumber(right)){
               return false;
            }
        break;
    }

  
    switch(operation){    
    case Operations::SUM:   
        cur_sum=left+right;
        left=cur_sum;
        break;
    case Operations::DIFF:        
        cur_sum=left - right;
        left=cur_sum;
        break;
    case Operations::MULT:             
        left *= right;
        break;
    case Operations::DIV:  
        if(right==0){
            flag_inf=true;          
        } else{
            left /= right;
        }        
        break;    
    case Operations::POW: 
        cur_sum = std::pow(left,right);       
        left = cur_sum;
        break;
    case Operations::SET:
        left = right;
        if(flag_inf) flag_inf=false;
        break;
    default:
       std::cout << "Unknown operation in switch" << oper << std::endl;
    break;
    }

    }
    return status;
}
