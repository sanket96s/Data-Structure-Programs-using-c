#include <stdio.h>
#include <string.h>
int i, flag = 0, top = -1;
char exp[100];

void push(int *stack, char ch)
{
    top++;
    stack[top] = ch;
}

void pop()
{
    top--;
}

void setexp()
{
    printf("\n Enter your expression : ");
    fgets(exp, sizeof(exp), stdin);
}

void checking()
{
    char ch;
    int stack[strlen(exp)];
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            ch = exp[i];
            push(&stack, ch);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (top == -1)
            {
                flag = 1;
                break;
            }
            else
            {
                if (exp[i] == ')' && stack[top] == '(')
                {
                    pop();
                }
                else if (exp[i] == ']' && stack[top] == '[')
                {
                    pop();
                }
                else if (exp[i] == '}' && stack[top] == '{')
                {
                    pop();
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
}

void main()
{
    setexp();
    printf("\n expression entered is : ");
    puts(exp);
    checking();

    if (flag == 1)
    {
        printf("\n Expression is not valid");
    }
    else if (top != -1)
    {
        printf("\n Expression is not valid");
    }
    else
    {
        printf("\n Expression is valid");
    }
}
