#include "EndOfSetExc.h"

const char* EndOfSetExc::what() const throw()
{
    std::string str = "No more elements!";
    return str.c_str();
}
