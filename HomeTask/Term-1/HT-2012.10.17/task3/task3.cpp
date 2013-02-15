#include <iostream>
#include <stdio.h>
#include <string.h>
int main()
{
	setlocale(LC_ALL, "Russian"); // russian language in comments
	std::cout << "Enter file name: ";
	char filename[1000];
	std::cin >> filename;
	FILE *f = fopen(filename, "r");
	char str[1000];
	bool isInMultilineComment = false;
	if (f != NULL)
	{
		while (!feof(f))
		{
			fgets(str, sizeof(str), f);
			int len = strlen(str);
			int pos = 0;
			bool flag = false;
			int quantOfQuotes = 0;
			int positionOfQuotes = 0;
			while (pos < len)
			{
				if (str[pos] == '/' && str[pos + 1] == '*')
				{
					isInMultilineComment = true;
				}
				else if (str[pos] == '*' && str[pos + 1] == '/')
					isInMultilineComment = false;
				else if (str[pos] == '"')
					quantOfQuotes++;
				else if (str[pos] == '/' && str[pos + 1] == '/' && !isInMultilineComment && quantOfQuotes % 2 == 0)
				{
					positionOfQuotes = pos;
					flag = true;
					if (flag)
						break;
				}
				pos++;
			}	
			if (flag)
			{
				for (int i = positionOfQuotes; i < len; i++)
					std::cout << str[i];
				quantOfQuotes = 0; 
				positionOfQuotes = 0;
			}
		}
		fclose(f);
	}
	else std::cout << "File is not open";
}
