#pragma once
#include <exception>
#include <string>

class FileIsNotOpenedExc : public std::exception
{
public:
     FileIsNotOpenedExc() {}
    virtual const char* what() const throw();
    ~FileIsNotOpenedExc() throw() {}
};
