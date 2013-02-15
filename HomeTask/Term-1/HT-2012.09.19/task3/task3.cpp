#include <iostream>
void sum(int arr[], int num, int quan, int pos)
{
	if (num == 0)
	{
		for (int i = 1; i <= pos - 1; i++)
		{
			std::cout << arr[i];
			if (i < pos - 1)
				std::cout << " + ";
		}
		std::cout << "\n";
	}
	else
		 for (int i = 1; i <= quan; i++)
		 	if (num - i >= 0)
			{
				arr[pos] = i;
				sum(arr, num - i, i, pos + 1);
			}
}
int main()
{
	int arr[100];
	std::cout << "n = ";
	int n;
	std::cin >> n;
	sum(arr, n, n, 1);
}
