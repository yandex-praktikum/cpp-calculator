// В этом файле только функция main и #include-директивы.
#include "calculator.h"

 int main(){
     bool run=true;
     while (run) {
        run = RunCalculatorCycle();
     }
    
    return 0;
}
