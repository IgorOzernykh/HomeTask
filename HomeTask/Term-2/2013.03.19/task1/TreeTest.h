#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "Tree.h"

class TreeTest : public QObject
{
    Q_OBJECT
private:
    Tree *tree;
    void createInFile()
    {
        std::fstream testInFile;
        testInFile.open("testIn.txt");
        testInFile << "(* (+ 12 1) 10)";
        testInFile.close();
    }

private slots:
    void init()
    {
        tree  = new Tree();
    }
    void testParse()
    {
        createInFile();
        tree->parse("testIn.txt");
    }

    void testCalc()
    {
        createInFile();
        tree->parse("testIn.txt");
        try
        {
            double result = tree->calc();
            QVERIFY(result == 130);
        }
        catch (IncorrectExprExc)
        {
            QFAIL("");
        }
    }
    void testPrint()
    {
        createInFile();
        std::fstream testOutFile;
        testOutFile.open("testOut.txt");
        tree->parse("testIn.txt");
        tree->print("testOut.txt");
        std::string expression;
        std::getline(testOutFile, expression);
        testOutFile.close();
        QVERIFY(expression == string("12 1 + 10 * "));
    }
    void cleanup()
    {
        delete tree;
    }
};
