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

bool isNumber (char *s)
{
	int state = start;
	int i = 0;
	while (1)
	{
		switch (state)
		{
		case fail:
			return false;
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
			return true;
		}
	}
}

bool E_NonTerminal (char *s, int &i);
bool Edash_NonTerminal (char *s, int &i);
bool T_NonTerminal (char *s, int &i);
bool Tdash_NonTerminal (char *s, int &i);
bool F_NonTerminal (char *s, int &i);

void skipBlanks (char *s, int &i)
{
	while (s[i] == ' ')
	{
		i++;
	}
}

bool F_NonTerminal (char *s, int &i) // F-> (E) | id
{
	if (s[i] == '(')
	{
		i++;
		skipBlanks (s, i);
		if (E_NonTerminal (s, i))
			if (s[i] == ')')
			{
				i++;
				return true;
			}
		return false;
	}
	else
	{
		int j = 0;
		char *buff = new char[100];
		if (s[i] == '-' && s[i] != '\0')
		{
			buff[j] = '-';
			i++;
			j++;
		}
		while (s[i] == '.' || s[i] == 'e' || s[i] == 'E' || s[i] >= '0' && s[i] <= '9' )
		{
			buff[j] = s[i];
			i++;
			j++;
		}
		buff[j] = '\0';
		if (isNumber(buff))
		{
			delete []buff;
			return true;
		}
		else 
		{
			delete []buff;
			return false;
		}
	}
}

bool Tdash_NonTerminal (char *s, int &i) // T' -> *FT' | /FT' | eps
{
	skipBlanks (s,i);
	if (s[i] == '*' || s[i] == '/')
	{
		i++;
		skipBlanks(s, i);
		if (F_NonTerminal (s, i))
			return Tdash_NonTerminal (s, i);
	}
	else return true;
}

bool T_NonTerminal (char *s, int &i) // T -> FT'
{
	if (F_NonTerminal(s, i))
		if (Tdash_NonTerminal(s, i))
			return true;
	return false;
}

bool Edash_NonTerminal (char *s, int &i) // E' -> +TE' | -TE' | eps
{
	skipBlanks (s, i);
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
		skipBlanks (s, i);
		if (T_NonTerminal (s, i))
			return Edash_NonTerminal (s, i);
	}
	else
		return true;
}

bool E_NonTerminal (char *s, int &i) // E -> TE'
{
	if (T_NonTerminal (s, i))
	{
		return Edash_NonTerminal(s ,i);
	}
	else
		return false;
}

bool isCorrect (char *string, int start)
{
	return E_NonTerminal (string, start);
}

int main()
{
	const int size = 100;
	char string[100];
	std::cout << "Enter an expression: ";
	std::cin.getline (string, size);
	if (isCorrect (string, 0))
		std::cout << "Expression is correct.\n";
	else 
		std::cout << "Expression is incorrect.\n";
	char exit;
	std::cout << "\nEnter any character to exit: ";
	std::cin >> exit;
}