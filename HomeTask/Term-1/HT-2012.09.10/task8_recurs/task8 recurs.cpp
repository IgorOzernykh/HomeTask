#include <iostream>
long fact(int n)
{
	if (n == 0)
		return 1;
	else
		if (n > 0)
        	return n * fact(n - 1);
}
int main()
{
	std::cout << "n = ";
	int n;
	std::cin >> n;
	if (n >= 0)
		std::cout << n << "! = " << fact(n);
	else 
		std::cout << "incorrect input";
}
