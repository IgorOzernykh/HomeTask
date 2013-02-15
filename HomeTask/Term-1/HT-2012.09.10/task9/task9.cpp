#include <iostream>
int main()
{
	int a;
	std::cout << "a = ";
	std::cin >> a;
	int n;
	std::cout << "n = ";
	std::cin >> n;
	int i;
	int deg = 1;
	for (i = 1; i <= n; i++)
		deg = deg * a;
	std:: cout << "a ^ n = " << deg;
}
