#include <iostream>
#include <string.h>

void swap(char &a, char &b)
{
	char c = a;
	a = b;
	b = c;
}

void quicksort (char s[], int low, int high)
{
	int i = low;
	int j = high;
	char m = s[(low + high) / 2];
	while (i <= j)
	{
		while (s[i] < m)
			i++;
		while (s[j] > m)
			j--;
		if (i <= j) 
		{
			swap(s[i], s[j]);
			i++;
			j--; 
		}
	}
	if (low < j)
		quicksort(s, low, j);
	if (i < high)
		quicksort(s, i, high);
}

int main()
{
	int const length = 200;
	char s1[length];
	char s2[length];
	std::cout << "s1 = ";
	std::cin.getline(s1, length);
	std::cout << "s2 = ";
	std::cin.getline(s2, length);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	bool flag = true;
	if (len1 == len2)
	{
		quicksort(s1, 0, len1 - 1);
		quicksort(s2, 0, len2 - 1);
		for (int i = 0; i < len1; i++)
			if (s1[i] != s2[i])
			{	
				flag = false;
				break;
			}
		if (flag)
			std::cout << "True";
		else std::cout << "False";
	}
	else std::cout << "False";		
}
