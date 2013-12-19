#include "Graph.h"

Graph::Graph(int amountOfVertices) :
    visited(amountOfVertices)
{
    for (int i = 0; i < amountOfVertices; i++)
    {
        adjMatrix.append(QVector<int>());
        for (int j = 0; j < amountOfVertices; j++)
        {
            adjMatrix[i].append(0);
        }
        visited.append(false);
        connectVertices(i, i);
    }
}

void Graph::connectVertices(int vertex_A, int vertex_B)
{
    adjMatrix[vertex_A][vertex_B] = 1;
    adjMatrix[vertex_B][vertex_A] = 1;
}

void Graph::disconnectVertices(int vertex_A, int vertex_B)
{
    adjMatrix[vertex_A][vertex_B] = 0;
    adjMatrix[vertex_B][vertex_A] = 0;
}

bool Graph::areConnected(int vertex_A, int vertex_B)
{
    return (adjMatrix[vertex_A][vertex_B] == 1);
}

QVector<int> Graph::getClassOfReachAbility(int startVertex)
{
    QVector<int> reachabilityClass;
    reachabilityClass.append(startVertex);
    QQueue<int> searchQueue;
    searchQueue.append(startVertex);
    while (!searchQueue.isEmpty())
    {
        QQueue<int> adjVertexQueue;
        for (int i = 0; i < adjMatrix.size(); i++)
        {
            if (areConnected(i, searchQueue.head()) && (i != searchQueue.head()) && !adjVertexQueue.contains(i))//&& !visited[i])
            {
                adjVertexQueue.push_back(i);
            }
        }
        while (!adjVertexQueue.isEmpty())
        {
            for (int i = 0 ; i < adjMatrix.size(); i++)
            {
                if (areConnected(i, adjVertexQueue.head()) && (i != adjVertexQueue.head()) && !visited[i] && !searchQueue.contains(i))
                {
                    searchQueue.push_back(i);
                    reachabilityClass.append(i);
                }
            }
            adjVertexQueue.pop_front();

        }
        visited[searchQueue.head()] = true;
        searchQueue.pop_front();
    }
    resetVisitedVertices();
    return reachabilityClass;
}

void Graph::resetVisitedVertices()
{
    for (int i = 0; i < visited.size(); i++)
    {
        visited[i] = 0;
    }
}
