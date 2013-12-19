#include <QCoreApplication>
#include "Graph.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int amountOfVertices = 0;
    std::cout << "Enter amount of vertices in the graph: ";
    std::cin >> amountOfVertices;
    Graph graph(amountOfVertices);
    std::cout << "For each vertex enter list of connected with it vertices:" << std::endl;
    std::cin.get();
    for (int j = 0; j < amountOfVertices; j++)
    {
        std::cout << j << ": ";
        char ch = std::cin.get();
        while (ch != '\n')
        {
            if (ch != ' ')
            {
                std::cin.putback(ch);
                int vertex = 0;
                std::cin >> vertex;
                graph.connectVertices(j, vertex);
            }
            ch = std::cin.get();
        }
        std::cout << std::endl;
    }
    QVector<int> robots;
    std::cout << "Enter robots' positions: ";
    char ch = std::cin.get();
    while (ch != '\n')
    {
        if (ch != ' ')
        {
            std::cin.putback(ch);
            int robotPos = 0;
            std::cin >> robotPos;
            robots.append(robotPos);
        }
        ch = std::cin.get();
    }
    std::cout << std::endl;

    bool result = true;
    int startVertex = 0;
    QVector< QVector<int> > classes;
    classes.append(graph.getClassOfReachAbility(0));
    for (int i = 0; i < amountOfVertices; i++)
    {
        if (graph.areConnected(i, startVertex))
        {
            classes.append(graph.getClassOfReachAbility(i));
            break;
        }
    }
    for (int i = 0; i < classes.size(); i++)
    {
        int robotsInClass = 0;
        for (int j = 0; j < robots.size(); j++)
        {
            if (classes[i].contains(robots[j]))
            {
                robotsInClass++;
            }
        }
        if (robotsInClass == 1)
        {
            result = false;
            break;
        }
    }

    if (result)
    {
        std::cout << "Robots can be destroyed!" << std::endl;
    }
    else
    {
        std::cout << "Robots can't be destroyed!" << std::endl;
    }

    return a.exec();
}

//#include "GraphTest.h"

//int main()
//{
//    GraphTest test;
//    QTest::qExec(&test);
//}
