#pragma once
#include <QTest>
#include "Graph.h"

class GraphTest : public QObject
{
    Q_OBJECT
private slots:
    /* Тестируем на графе (движение начинается с 0, в скобках достижимые):
              (2)
              / \
     (0) -- [1] [4] -- (5)
              \ /
              (3)
    */
    void get2ndReachableTest1()
    {
        Graph graph(6);
        graph.connectVertices(0, 1);
        graph.connectVertices(1, 2);
        graph.connectVertices(1, 3);
        graph.connectVertices(2, 4);
        graph.connectVertices(3, 4);
        graph.connectVertices(4, 5);

        QVector<int> actual = graph.getClassOfReachAbility(0);
        QVector<int> expected;
        expected  << 0 << 2 << 3 << 5;
        QCOMPARE(actual, expected);

        actual = graph.getClassOfReachAbility(1);
        expected.clear();
        expected << 1 << 4;
        QCOMPARE(actual, expected);
    }
    /* Тестируем на графе (движение начинается с A, в скобках достижимые):

          (1) ---
          /     |
        (0) -- (2)
    */
    void get2ndReachableTest2()
    {
        Graph graph(3);
        graph.connectVertices(0, 1);
        graph.connectVertices(0, 2);
        graph.connectVertices(1, 2);

        QVector<int> actual = graph.getClassOfReachAbility(0);

        QVector<int> expected;
        expected  << 0 << 2 << 1;
        QCOMPARE(actual, expected);
    }
    /* Тестируем на графе (движение начинается с A, в скобках достижимые):
                        (5)
                        / \
       (0) -- (1) -- (2) -- (4)
                      |
                     (3)
    */
    void get2ndReachableTest3()
    {
        Graph graph(6);
        graph.connectVertices(0, 1);
        graph.connectVertices(1, 2);
        graph.connectVertices(2, 3);
        graph.connectVertices(2, 4);
        graph.connectVertices(2, 5);
        graph.connectVertices(4, 5);

        QVector<int> actual = graph.getClassOfReachAbility(0);

        QVector<int> expected;
        expected  << 0 << 2 << 5 << 4 << 1 << 3;
        QCOMPARE(actual, expected);
    }
    void get2ndReachableTest4()
    {
        /*
        (0)-----(2)-----(7)---(8)
         |       | \     |\
         |       |  \    | \
         | (4)--(3)  \  (9) \
         |            \     (10)
         |             \
        (1)-----(5)-----(6)
         */
        Graph graph(11);
        graph.connectVertices(0, 1);
        graph.connectVertices(0, 2);
        graph.connectVertices(1, 5);
        graph.connectVertices(2, 3);
        graph.connectVertices(2, 6);
        graph.connectVertices(2, 7);
        graph.connectVertices(3, 4);
        graph.connectVertices(5, 6);
        graph.connectVertices(7, 8);
        graph.connectVertices(7, 9);
        graph.connectVertices(7, 10);

        QVector<int> actual = graph.getClassOfReachAbility(0);
        QVector<int> expected;
        expected  << 0 << 5 << 3 << 6 << 7 << 2 << 1 << 4 << 8 << 9 << 10;
        QCOMPARE(actual, expected);
    }
};
