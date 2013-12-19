#pragma once
#include <QQueue>
#include <QVector>

class Graph
{
public:
    Graph(int amountOfVertices);
    void connectVertices(int vertex_A, int vertex_B);
    void disconnectVertices(int vertex_A, int vertex_B);
    bool areConnected(int vertex_A, int vertex_B);
    QVector<int> getClassOfReachAbility(int startVertex);
private:
    void resetVisitedVertices();
    QVector < QVector<int> > adjMatrix;
    QVector<bool> visited;
};
