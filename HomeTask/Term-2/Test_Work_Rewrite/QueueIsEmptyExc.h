#pragma once
#include <exception>
#include <string>

class QueueIsEmptyExc : public std::exception
{
public:
    QueueIsEmptyExc(std::string descript) : description(descript) {}
    virtual const char* what() const throw();
    ~QueueIsEmptyExc() throw() {}
private:
    std::string description;
};
