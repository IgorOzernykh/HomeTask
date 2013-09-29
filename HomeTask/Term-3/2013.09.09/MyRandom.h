#pragma once
#include <stdlib.h>
#include <time.h>

class MyRandom
{
public:
    //vurtual MyRandom() = 0;
    //~MyRandom();
    virtual int random() = 0;
};

class RealRandom : public MyRandom
{
public:
    RealRandom() {}
    //~RealRandom();
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
    //~PseudoRandom();
    int random()
    {
        return 5;
    }
};
