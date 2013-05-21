#pragma once
#include <exception>
#include <string>

class EndOfSetExc : public std::exception
{
public:
    EndOfSetExc() {}
    virtual const char* what() const throw();
    ~EndOfSetExc() throw() {}
};
