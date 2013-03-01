#include "Stack.h"

Stack::Stack()
{
    elementsCounter = 0;
}

Stack::~Stack()
{

}

int Stack::Calculator(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int c = s[i] - '0';
            push(c);
        }
        else if (s[i] != ' ' && elementsCounter >=2)
        {
            int tmp1 = pop();
            int tmp2 = pop();
            switch (s[i])
            {
                case '-':
                {
                    push(tmp2 - tmp1);
                    break;
                }
                case '+':
                {
                    push(tmp2 + tmp1);
                    break;
                }
                case '/':
                {
                    push(tmp2 / tmp1);
                    break;
                }
                case '*':
                {
                    push(tmp2 * tmp1);
                    break;
                }
            }
        }
        i++;
    }
    return pop();
}
