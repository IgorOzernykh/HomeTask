#include "FileIsNotOpenedExc.h"

const char* FileIsNotOpenedExc::what() const throw()
{
    std::string str = "File is not opened.";
    return str.c_str();
}
