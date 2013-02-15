#include <iostream>
#include <string.h>
int main()
{
	char s[100];
	std::cout << "s = ";
	std::cin >> s;
	int i = 0;
	bool f = true;
	while ((i <= strlen(s) / 2) && f)
		if (s[i] != s[strlen(s) - i - 1])
			f = false;
		else 
			i++;
	if (f)
		std::cout << "TRUE";
	else
		std::cout << "FALSE";
}
