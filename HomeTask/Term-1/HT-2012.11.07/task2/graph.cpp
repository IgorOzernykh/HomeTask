#include "graph.h"
#include <limits.h>
#include <iostream>

Graph *createGraph(int cities)
{
	Graph *temp = new Graph;
	List **adlist = new List *[cities + 1];
	for (int i = 1; i <= cities; i++)
	{
		adlist[i] = createList();
		adlist[i]->verticeNumber = i;
		adlist[i]->way = new int [cities];
		adlist[i]->way[0] = 1;
		for (int j = 1; j < cities; j++)
			adlist[i]->way[j] = 0;
		adlist[i]->mark = INT_MAX;
	}
	adlist[1]->mark = 0;
	temp->amountOfVertices = cities;
	temp->adlist = adlist;
	return temp;
}

void add(Graph *graph, int city1, int city2, int length)
{
	addToList(graph->adlist[city1], city2, length);
	addToList(graph->adlist[city2], city1, length);
}

void capture (Graph *graph, int city, int distanceFromCity1, int j)
{
	if (graph->adlist[city]->head != nullptr)
	{
		ListElement *tmp = graph->adlist[city]->head;
		int i = 1;
		j++;
		while (i <= graph->adlist[city]->size)
		{
			if (tmp->arcWeight + distanceFromCity1 < graph->adlist[tmp->arcDirection]->mark)
			{
				graph->adlist[tmp->arcDirection]->mark = tmp->arcWeight + distanceFromCity1;
				for (int k = 1; k < j; k++)
					graph->adlist[tmp->arcDirection]->way[k] = graph->adlist[city]->way[k];
				graph->adlist[tmp->arcDirection]->way[j] = tmp->arcDirection;
				capture (graph, tmp->arcDirection, distanceFromCity1 + tmp->arcWeight, j);
			}
			if (i != graph->adlist[city]->size)
				tmp = tmp->next;
			i++;
		}
	}
	else return;
}

void capture (Graph *graph)
{
	int city = 1;
	int distanceFromCity1 = 0;
	int j = 0;
	capture (graph, city, distanceFromCity1, j);
}

void printStatistics(Graph *graph, int cities)
{
	int min = 0;
	int vertice;
	while (min != INT_MAX)
	{
		min = INT_MAX;
		for (int i = 1; i <= cities; i++)
		{
			if (graph->adlist[i]->mark > 0 && graph->adlist[i]->mark < min)
			{
				min = graph->adlist[i]->mark;
				vertice = graph->adlist[i]->verticeNumber;
			}
		}
		if (min != INT_MAX)
		{
			std::cout << vertice << ".  Distance from city 1 = " << graph->adlist[vertice]->mark << ".  Way: ";
			int j = 0;
			while (graph->adlist[vertice]->way[j] != vertice)
			{
				std::cout << graph->adlist[vertice]->way[j] << "-";
				j++;
			}
			std::cout << vertice << "\n";
		}
		graph->adlist[vertice]->mark = 0;
	}
}

void destroyGraph(Graph* graph, int cities)
{
	for (int i = 1; i <= cities; i++)
	{
		if (graph->adlist[i] != nullptr)
			destroyList(graph->adlist[i]);
		delete graph->adlist[i];
	}
	delete []graph->adlist;
	delete graph;
}