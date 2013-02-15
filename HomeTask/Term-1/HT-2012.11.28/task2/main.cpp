#include <iostream>

enum states
{
	fail = -1,
	start,
	first,
	second,
	third,
	fourth,
	fifth,
	sixth,
	seventh,
	success
};

void token (char s[])
{
	int state = start;
	int i = 0;
	bool flag = true;
	while (flag)
	{
		switch (state)
		{
		case fail:
			std::cout << "String is not a number\n";
			flag = false;
			break;
		case start:
			if (s[i] == '+' || s[i] == '-')
			{
				state = first;
				i++;
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				state = second;
				i++;
			}
			else if (s[i] == '.')
			{
				state = third;
				i++;
			}
			else state = fail;
			break;
		case first:
			if (s[i] >= '0' && s[i] <= '9')
			{
				i++;
				state = second;
			}
			else if (s[i] == '.')
			{
				state = third;
				i++;
			}
			else state = fail;
			break;
		case second:
			if (s[i] == '\0')
			{
				state = success;
			}
			else if (s[i] == '.')
			{
				state = third;
				i++;
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				i++;
			}
			else if (s[i] == 'e' || s[i] == 'E')
			{
				state = third;
				i++;
			}
			else state = fail;
			break;
		case third:
			if (s[i] >= '0' && s[i] <= '9')
			{
				state = fourth;
				i++;
			}
			else state = fail;
			break;
		case fourth:
			if (s[i] == '\0')
			{
				state = success;
			}
			else if (s[i] == 'E' || s[i] == 'e')
			{
				state = fifth;
				i++;
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				i++;
			}
			else state = fail;
			break;
		case fifth:
			if (s[i] == '+' || s[i] == '-')
			{
				state = sixth;
				i++;
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				state = seventh;
				i++;
			}
			else state = fail;
			break;
		case sixth:
			if (s[i] >= '0' && s[i] <= '9')
			{
				state = seventh;
				i++;
			}
			else state = fail;
			break;
		case seventh:
			if (s[i] == '\0')
			{
				state = success;
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				i++;
			}
			else state = fail;
			break;
		case success:
			std::cout << "String is a number.\n";
			flag = false;
			break;
		}
	}
}

int main()
{
	char string[100];
	std::cout << "Enter a number: ";
	std::cin >> string;
	token (string);
	char exit;
	std::cout << "\nEnter any character to exit: ";
	std::cin >> exit;
}