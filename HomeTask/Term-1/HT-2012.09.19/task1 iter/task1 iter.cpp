#include <iostream>
int main()
{
	std::cout << "enter the amount of numbers: ";
	int n;
	std::cin >> n;
	int ch1 = 1;
	int ch2 = 1;
	int ch3 = ch1 + ch2;
	std::cout << ch1 << " " << ch2 << " " << ch3 << " ";
	for (int i = 1; i <= n - 3; i++)
	{
		ch1 = ch2;
		ch2 = ch3;
		ch3 = ch1 + ch2;
		std::cout << ch3 << " ";
	}
	std::cout << "\n";
}
