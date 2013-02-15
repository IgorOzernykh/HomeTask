#include <iostream>
void swap(int &a, int &b)
{
	a = a xor b;
	b = a xor b;
	a = a xor b;
}
int main()
{	
	int m;
	std::cout << "m=";
	std::cin >> m;
	int n;
	std::cout << "n=";
	std::cin >> n;
	int x[m + n];
	int i;
	for (i = 1; i <= (m + n); i++)
	{
		std::cout << "x" << i << "=";
		std::cin >> x[i];
	}
	for (i = 1; i <= m / 2; i++)
		swap(x[i], x[m-i+1]);
	for (i = 1; i <= n / 2; i++)
		swap(x[m + i], x[m + n - i + 1]);	
	for (i = 1; i <= (m + n) / 2; i++)
		swap(x[i], x[m + n - i + 1]);
	for (i = 1; i <= m + n; i++)
		std::cout << x[i] <<" ";
}
