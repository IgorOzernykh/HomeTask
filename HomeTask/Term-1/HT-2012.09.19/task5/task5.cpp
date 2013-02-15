#include <iostream>
#include <stdlib.h>
void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
void downheap(int arr[], int i, int n)
{	
	int child;
	while (i <= n / 2)
	{
		child = 2 * i;
		if (child < n)
			if (arr[child + 1] < arr[child + 2])
				child += 2;
			else child++;
		if (child > n)
			child--;
		if (arr[i] > arr[child])
			break;
		swap(arr[i], arr[child]);
		i = child;
	}
}
void heapsort(int arr[], int n)
{
	for (int i = n / 2; i >= 0; i--)
		downheap(arr, i, n - 1);
	for (int i = n - 2; i > 0; i--)
	{
		swap(arr[0], arr[i + 1]);
		downheap(arr, 0, i);
	}	
	swap(arr[0], arr[1]);
}
int main()
{
	int n;
	std::cout << "Enter the size of array: ";
	std::cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand()%(5 * n);
	heapsort(arr, n);
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}
