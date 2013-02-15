#include <iostream>
void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
void quicksort (int mas[], int low, int high)
{
	int i = low;
	int j = high;
	int m = mas[(low + high) / 2];
	while (i <= j)
	{
		while (mas[i] < m)
			i++;
		while (mas[j] > m)
			j--;
		if (i <= j) 
		{
			swap(mas[i], mas[j]);
			i++;
			j--; 
		}
	}
	if (low < j)
		quicksort(mas, low, j);
	if (i < high)
		quicksort(mas, i, high);
}
int main ()
{	
	int k = 100;
	int mas[k];
	for (int i = 0; i < k; i++)
		mas[i] = rand()%k;
	std::cout << "\n";
	quicksort(mas, 0, k-1);
	for (int i = 0; i < k; i++)
		std::cout << mas[i] << " ";
	std::cout << "\n";
}
