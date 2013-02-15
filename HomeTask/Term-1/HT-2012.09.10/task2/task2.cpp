#include <iostream>
int main()
{
	int a;
	std::cout << "a=";
	std::cin >> a;
	int b;
	std::cout << "b=";
	std::cin >> b;
	int count = 0;
	while (a - b > 0) 
	{
		a = a - b;
		count++;
	}
	std::cout << count;
}
