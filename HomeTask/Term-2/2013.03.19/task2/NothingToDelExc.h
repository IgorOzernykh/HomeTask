#pragma once
#include <exception>
#include <string>

class NothingToDelExc : public std::exception
{
public:
    NothingToDelExc(std::string descript) : description(descript) {}
    virtual const char* what() const throw();
    ~NothingToDelExc() throw() {}
private:
    std::string description;
};
