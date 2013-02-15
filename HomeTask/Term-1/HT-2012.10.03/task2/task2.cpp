#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	std::cout << "Enter an odd number: ";
	std::cin >> n;
	int n2 = n*n;
	int arr[n2];
	srand(time(0));
	if (n % 2 == 1)
	{
		std::cout << "Basic array: \n";
		for (int i = 0; i < n2; i++)
		{
			arr[i] = rand()%25 + 10;
				std::cout << arr[i] << " ";
			if ((i+1) % n == 0)
				std::cout << "\n";
		}
		std::cout << "Spiral: \n";
		int i = n2 / 2;
		std::cout << arr[i] << " ";
		int numstep = 1;
		int stepsize = 2;
		for (int k = 1; k <= n / 2; k++)
		{
			if (numstep % 2 == 1 && stepsize % 2 == 0)
				for (int j = 1; j < stepsize; j++)
				{
					i++;
					std::cout << arr[i] << " ";
				}
				numstep++;
			if (numstep % 2 == 0 && stepsize % 2 == 0)
				for (int j = 1; j < stepsize; j++)
				{
					i += n;
					std::cout << arr[i] << " ";
				}
				numstep++;
				stepsize++;
			if (numstep % 2 == 1 && stepsize % 2 == 1)
				for (int j = 1; j < stepsize; j++)
				{
					i--;
					std::cout << arr[i] << " ";
				}
				numstep++;
			if (numstep % 2 == 0 && stepsize % 2 == 1)
				for (int j = 1; j < stepsize; j++)
				{
					i -= n;
					std::cout << arr[i] << " ";
					
				}
				numstep++;
				stepsize++;
		}
		for (int i = 1; i < n; i++)
			std::cout << arr[i] << " ";
	}	
	else std::cout << "Enter an odd n!";
}
