#include <iostream>
#include <string.h>
int main()
{
	std::cout << "s = ";
	char s[200];
	std::cin >> s;
	std::cout << "s1 = ";
	char s1[100];
	std::cin >> s1;
	int i;
	int j;
	int count = 0;
	bool f;
	for (i = 0; i <= strlen(s) - strlen(s1); i++)
	{
		j = 1;
		f = true;
		if (s[i] == s1[0])
		{
			while ((j <= strlen(s1) - 1) && f )
				if (s1[j] != s[i + j])
					f = false;
				else 
					j++;
			if (f) 
				count++;
		}
	}
	std::cout << "s1 in s -  " <<  count << " times";
}
