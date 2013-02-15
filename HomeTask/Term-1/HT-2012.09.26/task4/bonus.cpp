#include <iostream>
#include <time.h>
#include <stdlib.h>
using std::cout;
using std::cin;
int digit(int number)
{
	int count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return count;
}
int main()
{
	int degree;
	cout << "Enter the maximum degree of polynomial: ";
	cin >> degree;
	int coeff[degree + 1];
	srand(time(0));
	int deg = degree;
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = rand()%4 - 2;
	}
	cout << "\n";
	int k = 0;
	while (coeff[k] == 0 && deg >= 0)
	{
		k++;
		deg--;
	}
	int deg2 = deg;
	bool f = true;
	int count = 1;
	if (coeff[k] != 1 && coeff[k] != -1)
	{
		count += digit (coeff[k]);
		f = false;
		for (int j = 1; j <= count; j++)
			{
				cout << " ";
			}
		if (coeff[k] < 0 && coeff[k] != -1)
			cout << " ";
	}
	else if (coeff[k] == 1)
	{
		f = false;
		cout << " ";
	}
	else if (coeff[k] == -1)
	{
		f = false;
		cout << "  ";
	}
	if (!f && deg > 1)
	{
		cout << deg;
		deg--;
	}
	for (int i = k + 1; i <= degree; i++)
	{
		count = 2;
		if (coeff[i] != 0)
		{
			if (coeff[i] != 1 && coeff[i] != -1)
			{
				count += digit (coeff[i]);
				for (int j = 1; j <= count; j++)
					cout << " ";
			}
			else if (coeff[i] == 1 || coeff[i] == -1)
			{
				cout << "  ";
			}
		}
		if (deg > 1 && coeff[i] != 0)
		{
			cout << deg;
		}
		deg--;
	}
	cout << "\n";
	deg = deg2;
	if (coeff[k] != 1 && coeff[k] != -1)
	{
		cout << coeff[k];
	}
	else if (coeff[k] == -1)
		cout << "-";
	if (deg > 0)
		cout << "x";
	count = 0;
	if	(deg > 1)
		count = digit(deg);
	for (int j = 1; j <= count; j++)
	{
		cout << " ";
	}
	deg--;
	for (int i = k + 1; i <= degree; i++)
	{
		count = 0;
		if	(deg > 1)
			count = digit(deg);
		if (coeff[i] != 0)
		{
			if (coeff[i] == 1)
				cout << "+";
			else if (coeff[i] == -1)
				cout << "-";
			else if (coeff[i] > 0)
			{
				cout << "+";
				cout << coeff[i];
			}
			else if (coeff[i] < 0)
				cout << coeff[i];
		}
		if (deg > 0 && coeff[i] != 0)
		{
			cout << "x";
			for (int j = 1; j <= count; j++)
			{
				cout << " ";
			}
		}
		deg--;	
	}
	if (coeff[degree] != 0 && (coeff[degree] == 1 || coeff[degree] == -1))
	{
		cout << "1";
	}
	cout << "\n";
}
