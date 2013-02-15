#include <iostream>
int main()
{	
	int sum[28];
	int i;
	for (i = 1; i <= 27; i++)
		sum[i] = 0;
	int j;
	int k;
	for (i = 0; i <= 9; i++)
		for (j = 0; j <= 9; j++)
			for (k = 0;  k <= 9; k++)
				sum[i + j + k]++;
	int count = 0;
	for (i = 1; i <= 27; i++)
		count = count + sum[i] * sum[i];
	std::cout << "Quantity of lucky tickets is " << count;
}
