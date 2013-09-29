#include "Network.h"

Network::Network(int nwSize, MyRandom *rndType) :
    networkSize(nwSize),
    compCounter(0),
    randType(rndType)
{
    compList = new Computer *[networkSize];
    connectionList = new int *[networkSize];
    for (int i = 0; i < networkSize; i++)
    {
        connectionList[i] = new int[networkSize];
        for (int j = 0; j < networkSize; j++)
        {
            if (i == j)
            {
                connectionList[i][j] = 1;
            }
            else
            {
                connectionList[i][j] = 0;
            }
        }
    }
}

Network::~Network()
{
    for (int i = 0; i < compCounter; i++)
    {
        delete compList[i];
    }
    delete compList;
    for (int i = 0; i < networkSize; i++)
    {
        delete connectionList[i];
    }
    delete connectionList;
    //delete randType;
}

void Network::addComputer (OS operationSystem)
{
    if (compCounter < networkSize)
    {
        switch (operationSystem)
        {
        case Windows:
        {
            compList[compCounter++] = new WindowsComputer;
            break;
        }
        case Mac:
        {
            compList[compCounter++] = new MacComputer;
            break;
        }
        case Linux:
            compList[compCounter++] = new LinuxComputer;
            break;
        }
    }
}

void Network::connectComputers (int first, int second)
{
    connectionList[first][second] = 1;
    connectionList[second][first] = 1;
}

void Network::disconnectComputers (int first, int second)
{
    connectionList[first][second] = 0;
    connectionList[second][first] = 0;
}
bool Network::areConnected(int first, int second)
{
    return connectionList[first][second] == 1;
}

void Network::infect (Computer *comp)
{
    if (!comp->getInfectStatus())
    {
        //srand(time(0));
        //if (comp->getInfectChance() >= rand() % 101)
        if (comp->getInfectChance() >= randType->random() % 101)
        {
            comp->setInfectStatus(true);
        }
    }
}
