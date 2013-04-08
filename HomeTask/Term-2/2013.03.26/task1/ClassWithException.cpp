#include "ClassWithException.h"

ClassWithException::ClassWithException() throw (MyException)
{
    cout << "ClassWithException Constructor" << endl;
    throw MyException();
}

ClassWithException::~ClassWithException()
{
    cout << "ClassWithException Destructor" << endl;
}
