#include "list.h"
#pragma once

struct Graph
{
	int amountOfVertices;
	List **adlist;
};

Graph *createGraph(int cities);
void add(Graph *graph, int from, int to, int length);
void capture (Graph *graph);
void printStatistics(Graph *graph, int amountOfCities);
void destroyGraph(Graph* graph, int cities);