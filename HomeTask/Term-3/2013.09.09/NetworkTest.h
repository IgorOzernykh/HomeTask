#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "Network.h"

class NetworkTest : public QObject
{
    Q_OBJECT
private:
    Network *network;
    MyRandom *rndType;
private slots:
    void init()
    {
        rndType = new PseudoRandom;
        network = new Network(10, rndType);
    }
    void addCompTest()
    {
        network->addComputer(Windows);
        network->addComputer(Mac);
        network->addComputer(Linux);
        QVERIFY(network->getCompCounter() == 3);
    }
    void connectComputersTest()
    {
        network->addComputer(Windows);
        network->addComputer(Mac);
        network->addComputer(Linux);
        network->addComputer(Windows);
        network->addComputer(Mac);
        network->addComputer(Linux);
        network->connectComputers(0, 1);
        network->connectComputers(0, 3);
        network->connectComputers(0, 5);
        network->connectComputers(1, 3);
        network->connectComputers(2, 4);
        network->connectComputers(2, 5);
        network->connectComputers(3, 5);
        QVERIFY(network->areConnected(0,1));
        QVERIFY(network->areConnected(0,3));
        QVERIFY(network->areConnected(0,5));
        QVERIFY(network->areConnected(1,3));
        QVERIFY(network->areConnected(2,4));
        QVERIFY(network->areConnected(2,5));
        QVERIFY(network->areConnected(3,5));
    }
    void infectTest()
    {
        network->addComputer(Windows);
        network->infect(network->getCompList()[0]);
        QVERIFY(network->getCompList()[0]->getInfectStatus());
    }
    void NwTest()
    {
        network->addComputer(Windows);
        network->addComputer(Mac);
        network->addComputer(Linux);
        network->addComputer(Windows);
        network->addComputer(Mac);
        network->addComputer(Linux);
        network->connectComputers(0, 1);
        network->connectComputers(0, 3);
        network->connectComputers(0, 5);
        network->connectComputers(1, 3);
        network->connectComputers(2, 4);
        network->connectComputers(2, 5);
        network->connectComputers(3, 5);

        qDebug() << "Computer 0 is connected with 1, 3, 5";
        qDebug() << "Computer 1 is connected with 0, 3";
        qDebug() << "Computer 2 is connected with 4, 5";
        qDebug() << "Computer 3 is connected with 0, 1, 5";
        qDebug() << "Computer 4 is connected with 2";
        qDebug() << "Computer 5 is connected with 0, 2, 3";
        int notInfectedCounter = 6;
        int j = 0;
        while (notInfectedCounter != 0)
        {
            int i = j;
            qDebug() << "Quantity of infected computers: " << network->getCompCounter() - notInfectedCounter;
            network->infect(network->getCompList()[i]);
            QVERIFY(network->getCompList()[i]->getInfectStatus());
            qDebug() << "Computer " << i << " has been infected";
            notInfectedCounter--;
            for (j = 0; j < network->getCompCounter(); j++)
            {
                if (i != j && network->areConnected(i,j) == 1 && !network->getCompList()[j]->getInfectStatus())
                {
                    qDebug() << "Next computer to be infected is " << j;
                    break;
                }
            }
        }
        qDebug() << "Quantity of infected computers: " << network->getCompCounter() - notInfectedCounter;
    }

    void cleanup()
    {
        delete rndType;
        delete network;
    }
};
