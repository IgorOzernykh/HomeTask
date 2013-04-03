#include "AlreadyExistExc.h"

const char* AlreadyExistExc::what() const throw()
{
    std::string str = "Item is already exist.";
    return str.c_str();
}
