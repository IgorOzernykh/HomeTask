#include "QueueIsEmptyExc.h"

const char* QueueIsEmptyExc::what() const throw()
{
    std::string str = description;
    return str.c_str();
}
