// В этом файле объявления функций.
#pragma once

using Number = double;

enum class Operations{
    SUM,
    DIFF,
    MULT,
    DIV,
    POW,
    MEM,
    LOAD,
    CALC,
    QUIT,
    SET,
    CLEAR,

};

bool ReadNumber(Number &result);
bool ReadOperation(int &oper);
bool RunCalculatorCycle();
