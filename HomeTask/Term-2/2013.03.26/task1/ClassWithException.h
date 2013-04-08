#pragma once
#include "ExampleClass.h"

class MyException {};

class ClassWithException
{
public:
    ClassWithException() throw (MyException);
    ~ClassWithException();
private:
    ExampleClass example;
};


