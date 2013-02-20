#include <iostream>
#include <stdlib.h>
void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
void quicksort (int arr[], int low, int high)
{
	int i = low;
	int j = high;
	int m = arr[(low + high) / 2];
	while (i <= j)
	{
		while (arr[i] < m)
			i++;
		while (arr[j] > m)
			j--;
		if (i <= j) 
		{
			swap(arr[i], arr[j]);
			i++;
			j--; 
		}
	}
	if (low < j)
		quicksort(arr, low, j);
	if (i < high)
		quicksort(arr, i, high);
}
int main()
{
	int n;
	std::cout << "Enter the size of array: ";
	std::cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand()%(50);
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	quicksort(arr, 0, n - 1);
	int i = n - 1;
	while (i > 1 && arr[i] != arr[i - 1])
		i--;
	if (i == 1 && arr[1] != arr[0])
		std::cout << "No such elements";
	else
		std::cout << arr[i];
	std::cout << "\n";
}
