#pragma once
#include <QString>

class Calculator
{
public:
    Calculator();
    double calculate (double arg1, double arg2, QString operation) throw(QString*);
};

