#include <iostream>
#include <string.h>
int main()
{
	int const length = 1000;
	char s[length];
	std::cout << "Enter text:";
	std::cin.getline(s, length);
	int len = strlen(s);
	int i = 0;
	while (i < len)
	{
		int start;
		if (s[i] != ' ')
			start = i;
		else if (s[i] == ' ')
			start = i + 1;
		int end = start;
		while (s[end] != ' ' && end < len)
		{
			end++;
		}
		for (int j = start; j < end; j++)
		{
			bool flag = true;
			for (int k = j + 1; k <= end; k++)
			{
				if (s[j] != 1 && (s[j] == s[k] || s[j] == s[k] - 32))
				{
					if (flag)
						std::cout << s[j];
					s[k] = 1;
					flag = false;
				}
			}
			if (flag && s[j] != 1)
				std::cout << s[j];
		}
		std::cout << " ";
		i = end + 1;
	}
}
