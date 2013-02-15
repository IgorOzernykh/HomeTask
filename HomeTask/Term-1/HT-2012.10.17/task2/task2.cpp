#include <iostream>
void printmant(unsigned long long num)
{
	unsigned long long mant = 0;
    int quantofzeros = 0;
    long long factor = 1;
    unsigned long long limit = 0;
    limit = ~limit;
    limit /= 10;
    unsigned long long current = 1;
    current <<= 51;
    unsigned long long signifBit = 0;
    signifBit = ~signifBit;
    signifBit >>=12;
    while (signifBit & num)
    {
        if (mant <= limit)
        {
            mant *= 10;
            factor *= 5;
        }
        else factor /= 2;
    	if ((mant == 0) && (!(current & num)))
        {
        	quantofzeros++;
        }
        if (current & num)
        {
            mant += factor;
        }
        current >>= 1;
        signifBit >>= 1; 
    }
    for (int i = 1; i <= quantofzeros - 1; i++)
    {
		std::cout << '0';
    }
    std::cout << mant;
}
void printexponent(unsigned long long num)
{
	num <<=1;
    num >>=53;
    num = num - 1023;
    std::cout << "*2^(" << num << ")";
}
int main()
{
	double num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	unsigned long long *number = (unsigned long long*)&num;
	if (num != 0)
	{	
		if (num > 0)
			std::cout << "+1.";
		else if (num < 0)
			std::cout << "-1.";
		printmant(*number);
		printexponent(*number);
	}
	else std::cout << "You have entered zero!";
}
