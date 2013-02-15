#include <iostream>
#include "graph.h"
#include <fstream>

int main()
{
	char filename[200];
	std::cout << "Enter file name: ";
	std::cin >> filename;
	std::ifstream file(filename);
	if (file != nullptr)
	{
		int amountOfCities;
		file >> amountOfCities;
		int amountOfRoads;
		file >> amountOfRoads;
		Graph *graph = createGraph(amountOfCities);
		for (int i = 0; i < amountOfRoads; i++)
		{
			int city1;
			int city2;
			int length;
			file >> city1;
			file >> city2;
			file >> length;
			add(graph, city1, city2, length);
		}
		capture(graph);
		printStatistics(graph, amountOfCities);
		destroyGraph(graph, amountOfCities);
	}
	else 
		std::cout << "File is not open\n";
	char exit;
	std::cout << "\nEnter any character to exit: ";
	std::cin >> exit;
}