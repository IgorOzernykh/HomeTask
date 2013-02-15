#include <iostream>
#include "list.h"
#include <vld.h>
char menu()
{
	char key;
	std::cout << "\n0 - exit\n"
		 << "1 - check the equality\n"
		 << "2 - calcutate the value at x\n"
		 << "3 - calculate the sum of polynimials\n";
	while (1)
	{
		std::cin >> key;
		if (key == '0' || key == '1' || key == '2' || key == '3')
			break;
		else 
		{
			std::cout << "\nIncorrect input\n\n";
			break;
		}
	}
	return key;
}


int main()
{
	List *p = createList();
	int degp;
	std::cout << "\nEnter the maximum degree of polynomial p: ";
	std::cin >> degp;
	p->size = degp;
	for (int i = degp; i >= 0; i--)
	{
		int coeff;
		std::cout << "Enter coefficient A" << degp - i << ": ";
		std::cin >> coeff;
		addElementToPolynom (p, i, coeff);
	}

	List *q = createList();
	int degq;
	std::cout << "\nEnter the maximum degree of polynomial q: ";
	std::cin >> degq;
	q->size = degq;
	for (int i = degq; i >= 0; i--)
	{
		int coeff;
		std::cout << "Enter coefficient A" << degq - i << ": ";
		std::cin >> coeff;
		addElementToPolynom (q, i, coeff);
	}
	char key = 'x';
	while (key != '0')
	{
		key = menu();
		if (key == '1')
		{
			if (equals (p,q))
				std::cout << "\nPolynomials are equal\n";
			else std::cout << "\nPolynomials are not equal\n";
		}
		else if (key == '2')
		{	
			char polynomial;
			std::cout << "\nChoose the polynomial: p or q?\n";
			std::cin >> polynomial;
			int x;
			std::cout << "\nEnter x: ";
			std::cin >> x;
			long long int result;
			if (polynomial == 'p')
				 result = value(p, x);
			else if (polynomial == 'q')
				result = value(q, x);
			std::cout << "\nResult = " << result << "\n";
		}
		else if (key == '3')
		{
			List *r = createList();
			add(p, q, r);
			std::cout << "\n";
			printPolynomial(r);
			destroyList(r);
		}
	}
	if (key == '0')
		std::cout << "\nProgram has finished\n\n";
	destroyList(p);
	destroyList(q);
	char exit;
	std::cout << "\nEnter any character to exit: ";
	std::cin >> exit;
}