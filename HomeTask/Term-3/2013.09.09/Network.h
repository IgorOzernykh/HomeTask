#pragma once
#include "Computer.h"
//#include <stdlib.h>
//#include <time.h>
#include "MyRandom.h"

/** Network class is model of a local network.
    You can add computers to the network, connect and disconnect computers
    and pull viruses into network
  */

class Network
{
public:
    Network(int nwSize, MyRandom *rndType);
    ~Network();
    void addComputer (OS operationSystem);
    void connectComputers (int first, int second);
    void disconnectComputers (int first, int second);
    /** pull the virus into network and try to infect computer you want to */
    void infect (Computer *comp);
    /** check whether computers connected directly */
    bool areConnected (int first, int second);
    int getCompCounter()
    {
        return compCounter;
    }
    int **getConnectionList()
    {
        return connectionList;
    }
    Computer **getCompList()
    {
        return compList;
    }
private:
    int networkSize;
    int compCounter;
    int **connectionList;
    Computer **compList;
    MyRandom *randType;
};
