#include <iostream>
int numfib(int n)
{
	if (n <= 2)
		return 1;
	else
		return numfib(n - 1) + numfib(n - 2);
}
int main()
{
	std::cout << "enter the amount of numbers: ";
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cout << numfib(i) << " ";
	std::cout << "\n";
}
