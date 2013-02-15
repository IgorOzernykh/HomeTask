#include <iostream>
#include <stdlib.h>
#include <time.h>
void swap (int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main()
{
	std::cout << "Enter array size: ";
	int size;
	std::cin >> size;
	int arr[size];
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand()%100 - 50;
	}
	std::cout << "Basic array: \n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}	
	std::cout << "\n\n";
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
	std::cout << "Sorted array: \n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

