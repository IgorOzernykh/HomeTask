#include <iostream>
#include <string.h>
int main()
{
	char s[100];
	std::cout << "s:";
	std::cin >> s;
	int count = 0;
	bool f = true;
	int i = 0;
		while ((i <= strlen(s)) && f) 
		{
			if (s[i] == '(') 
				count++;
			else 
				if (s[i] == ')')
					count = count - 1;
			if (count < 0)
				f = false;
			else 
				i++;
		}
	if (f && count == 0)
		std::cout << "TRUE";
	else 
		std::cout << "FALSE";
}
