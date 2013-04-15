#include "NothingToDelExc.h"

const char* NothingToDelExc::what() const throw()
{
    std::string str = "Nothing to delete: " + description;
    return str.c_str();
}
