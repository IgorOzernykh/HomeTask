#include <iostream>
int main()
{
	std::cout << "a = ";
	int a;
	std::cin >> a;
	std::cout << "n = ";
	int n;
	std::cin >> n;
	long degree = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
			degree *= a;
		n /= 2;
		a *= a;
	}
	std::cout << "a^n = " << degree << "\n";
}
