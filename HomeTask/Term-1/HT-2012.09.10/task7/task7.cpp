#include <iostream>
int main()
{
	int n;
	std::cout << "n= ";
	std::cin >> n;
	int i;
	int j;
	bool t;
	for (i = 2; i <= n; i++)
	{	
		t = true;
		j = 2;
		while (j <= i / 2 and t)
			if (i % j == 0)
				t = false;
			else
				j++;
			if (t) 
				std::cout << i << " ";
	}
			
}
