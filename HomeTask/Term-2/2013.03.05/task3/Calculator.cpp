#include "Calculator.h"

Calculator::Calculator()
{
}

double Calculator::calculate(double arg1, double arg2, QString operation) throw (QString*)
{
    double result = 0;
    if (operation == "+")
    {
        result = arg1 + arg2;
    }
    else if (operation == "-")
    {
        result = arg1 - arg2;
    }
    else if (operation == "*")
    {
        result = arg1 * arg2;
    }
    else if (operation == "/")
    {
        if (arg2 == 0)
            throw new QString("Division by zero!");
        result = double(arg1) / double(arg2);
    }
    return result;
}
