#pragma once
#include <stdlib.h>
#include <time.h>

/** MyRandom class. Has two inherited classes:
    RealRandom that use rand() from stdlib.h
    and PseudoRandom that returns constant value (to be sure that smth I need will happen) */

class MyRandom
{
public:
    virtual int random() = 0;
};

class RealRandom : public MyRandom
{
public:
    RealRandom() {}
    int random()
    {
        srand(time(0));
        return rand();
    }
};

class PseudoRandom : public MyRandom
{
public:
    PseudoRandom() {}
    int random()
    {
        return 5;
    }
};
