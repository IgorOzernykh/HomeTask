#pragma once
#include <exception>
#include <string>

class AlreadyExistExc : public std::exception
{
public:
    AlreadyExistExc() {}
    virtual const char* what() const throw();
    ~AlreadyExistExc() throw() {}

};
