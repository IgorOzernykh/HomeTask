#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "Calculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorTest(QObject *parent = 0):QObject(parent) {}
private:
    Calculator calc;
private slots:
    void testComposition()
    {
        QVERIFY(calc.calculate(1.89, -6.92, "+") == -5.03);
    }
    void testSubtraction()
    {
        QVERIFY(calc.calculate(1.89, -6.92, "-") == 8.81);
    }
    void testMultiplication()
    {
        QVERIFY(calc.calculate(2, -6.92, "*") == -13.84);
    }
    void testDivision()
    {
        QVERIFY(calc.calculate(10.5, 0.5, "/") == 21);
    }
    void testDivisionByZero()
    {
        try
        {
            calc.calculate(1.2, 0, "/");
        }
        catch (QString *exception)
        {
            QVERIFY(exception == QString("Division by zero!"));
        }
    }
};
//QTEST_MAIN(CalculatorTest)

