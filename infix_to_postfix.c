#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char infix[100], postfix[100];


int top = -1;
char stack[100];

void push(char item)
{
    top = top + 1;
    stack[top] = item;
}

char pop()
{
    char item;

    if (top < 0)
    {
        printf("\nStack Underflow!");
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

int is_operator(char op)
{
    if (op == '^' || op == '*' || op == '/' || op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infixToPostfix()
{
    char temp, item;
    int i = 0, j = 0;
    push('(');
    strcat(infix, ")");
    item = infix[i];
    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix[j] = item;
            j++;
        }
        else if (is_operator(item) == 1)
        {
            temp = pop();
            while (is_operator(temp) == 1 && check_precedence(temp) >= check_precedence(item))
            {
                postfix[j] = temp;
                j++;
                temp = pop();
            }
            push(temp);
            push(item);
        }
        else if (item == ')')
        {
            temp = pop();
            while (temp != '(')
            {
                postfix[j] = temp;
                j++;
                temp = pop();
            }
        }
        else
        {
            printf("\nInvalid expression!");
            exit(1);
        }
        i++;
        item = infix[i];
    }
    postfix[j] = '\0';
}

int main()
{
    printf("\n Enter a valid infix expression: ");
    gets(infix);
    infixToPostfix();
    printf("\npostfix expression is %s", postfix);
    return 0;
}
