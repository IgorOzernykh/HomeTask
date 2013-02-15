#include <iostream>
int main()
{
	std::cout << "n = ";
	int n;
	std::cin >> n;
	if (n >= 0)
	{
		int i;
		long fact = 1;
		for (i = 2; i <= n; i++)
			fact = fact * i;
		std::cout << "n! = " << fact;
	}
	else 
		std::cout << "incorrect input";
}	
