#include <stdio.h>
#include <ctype.h>
int stack[100];
int top = -1, i = 0;
char exp[100];

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

void answer()
{
    int n1, n2;
    char ch;
    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];
        if (isdigit(ch))
        {
            ch = ch - 48;
            push(ch);
        }
        else
        {
            n1 = pop();
            n2 = pop();

            switch (ch)
            {
            case '+':
                push(n2 + n1);
                break;
            case '-':
                push(n2 - n1);
                break;
            case '*':
                push(n2 * n1);
                break;
            case '/':
                push(n2 / n1);
                break;
            }
        }
    }
    printf("\n Answer is : %d", pop());
}

int main()
{
    printf("Enter the expression :: ");
    scanf("%s", exp);
    printf("%s", exp);
    answer();
    return 0;
}
