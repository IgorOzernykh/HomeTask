#include <iostream>
#include <string.h>
struct StackElement
{
	char action;
	int priority;
	StackElement *next;
};
struct Stack
{
	StackElement *head;
};
Stack *createStack()
{
	Stack *stack = new Stack;
	stack->head = NULL;
	return stack;
}
int main()
{
	char s[100];
	std::cout << "Enter the expression: ";
	std::cin >> s;
	int len = strlen(s);
	int pr = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
			pr += 2;
		else 
		 if (s[i] == ')')
		 	pr -= 2;
		else	 	
		 if (s[i] >= '0' && s[i] <= '9')
			std::cout << s[i] << " ";
		 else
		  if (s[i] == '+' or s[i] == '-')
	{}	  	
	}
}
