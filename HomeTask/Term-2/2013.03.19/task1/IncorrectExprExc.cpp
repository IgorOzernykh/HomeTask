#include "IncorrectExprExc.h"

const char* IncorrectExprExc::what() const throw()
{
    std::string str = "Incorrect expression: " + description;
    return str.c_str();
}
