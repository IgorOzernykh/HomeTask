#pragma once
#include <exception>
#include <string>

class IncorrectExprExc : public std::exception
{
public:
    IncorrectExprExc(std::string descript): description(descript) {}
    virtual const char* what() const throw();
    ~IncorrectExprExc() throw() {}
private:
    std::string description;
};
