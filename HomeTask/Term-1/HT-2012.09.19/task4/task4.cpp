#include <iostream>
int nod(int a, int b)
{
	if (a > b)
		nod(a - b, b);
	else 
	if (a < b)
			nod(a, b - a);
	else
	if (a == b)
		return a;
}
int main()
{
	std::cout << "n = ";
	int n;
	std::cin >> n;
	int numerator[200];
	int denominator[200];
	int num = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (nod(j, i) == 1)
				{
					numerator[num] = j;
					denominator[num] = i;
					num++;
				}
	for (int i = 0; i < num; i++)
		{
		float min = 1;
		int minj;
		for (int j = 0; j < num; j++)
			if (float(numerator[j]) / denominator[j] < min)
				{
					min = float(numerator[j]) / denominator[j];
					minj = j;
				}
			std::cout << numerator[minj] << "/" << denominator[minj] << " ";
		denominator[minj] = 1;
	}
}
