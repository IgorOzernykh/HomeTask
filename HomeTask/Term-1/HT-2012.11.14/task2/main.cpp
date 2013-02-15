#include <iostream>
#include <string.h>

const int mod = 1028201;
long long int hash (char s[], int start, int end)
{
	long long int hash = 0;
	long long int base = 1;
	const int factor = 2;
	for (int i = start; i <= end; i++)
	{
		hash += (int(s[end + start - i]) * base) % mod;
		base *= factor;
	}
	return hash % mod;
}

long long int rehash (char oldSym, char newSym, int oldhash, int length)
{
	unsigned long long int base = 1;
	const int factor = 2;
	for (int i = 1; i < length; i++)
	{
		base *= factor;
	}
	long long int tmp = oldhash - int(oldSym) * base % mod;
	if (tmp > 0)
		tmp %= mod;
	else while (tmp < 0)
		tmp += mod;
	tmp = (tmp * factor) % mod + newSym;
	return tmp % mod;
}

bool RabinKarp (char string[], char substring[])
{
	int sublength = strlen (substring);
	int length = strlen (string);
	int checkLength = length - sublength + 1;
	long long int subHash = hash(substring, 0, sublength - 1);
	long long int stringHash = hash (string, 0, sublength - 1);
	int i = 0;
	bool flag = false;
	while (i < checkLength)
	{
		if (stringHash == subHash)
		{
			bool areEqual = true;
			for (int j = 0; j < sublength; j++)
			{
				if (string[i + j] != substring[j])
				{
					areEqual = false;
					break;
				}
			}
			if (areEqual)
			{
				flag = true;
				std::cout << "From position " << i << " to " << i + sublength - 1 << "\n";
				i += sublength;
				stringHash = hash (string, i, i + sublength - 1);
			}
			else
			{
				stringHash = rehash(string[i], string[i + sublength], stringHash, sublength);
				i++;
			}
		}
		else
		{
			stringHash = rehash(string[i], string[i + sublength], stringHash, sublength);
			i++;	
		}
	}
	return flag;
}

int main()
{
	const int length = 1000;
	char string[length];
	std::cout << "Enter a string: ";
	std::cin.getline(string, length);
	char substring[length];
	std::cout << "Enter a substring: ";
	std::cin.getline(substring, length);
	if (!RabinKarp(string, substring))
		std::cout << "No '" << substring << "'\nin '" << string << "'\n";
	char exit;
	std::cout << "\nEnter any character to exit: ";
	std::cin >> exit;
}