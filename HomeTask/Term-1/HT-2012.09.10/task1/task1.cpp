#include <iostream>
int main()
{
	int x;
	std::cout << "x=";
	std::cin >> x;
	int a = x * x;
	a = (a + x) * (a + 1) + 1;
	std::cout << a;
}
