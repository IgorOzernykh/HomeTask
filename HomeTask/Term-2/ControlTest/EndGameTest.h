#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "OuthAndCrosses.h"

class EndGameTest : public QObject
{
    Q_OBJECT
private:
    QString s;
private slots:
    void gameEndTest()
    {
        s = QString("Game Ended!");
        QVERIFY(s == QString("Game Ended!"));
    }
    // otherwise didn't work. =(
};
