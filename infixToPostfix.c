#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Global variables
char infix[100], postfix[100];
int top = -1;
char stack[100];

// Function to push an element onto the stack
void push(char item)
{
    top++;
    stack[top] = item;
}

// Function to pop an element from the stack
char pop()
{
    char item;

    if (top < 0)
    {
        printf("\n Stack Underflow!");
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

// Function to check if a character is an operator
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

// Function to check the precedence of an operator
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

// Function to convert infix expression to postfix expression
void infixToPostfix()
{
    char temp, item;
    int i = 0, j = 0;

    // Push '(' onto the stack to handle the first '('
    push('(');
    // Append ')' to the infix expression to denote the end
    strcat(infix, ")");
    // Get the first character of the infix expression
    item = infix[i];

    // Iterate through each character of the infix expression
    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            // Append operands directly to the postfix expression
            postfix[j] = item;
            j++;
        }
        else if (is_operator(item) == 1)
        {
            // If an operator is encountered, pop operators with higher or equal precedence
            // from the stack and append them to the postfix expression
            temp = pop();
            while (is_operator(temp) == 1 && check_precedence(temp) >= check_precedence(item))
            {
                postfix[j] = temp;
                j++;
                temp = pop();
            }
            // Push the current operator onto the stack
            push(temp);
            push(item);
        }
        else if (item == ')')
        {
            // If a ')' is encountered, pop operators from the stack and append them to
            // the postfix expression until a '(' is encountered
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
        // Move to the next character in the infix expression
        i++;
        item = infix[i];
    }
    // Null terminate the postfix expression
    postfix[j] = '\0';
}

// Main function
void main()
{
    // Prompt the user to input a valid infix expression
    printf("\n Enter a valid infix expression (without spaces) : ");
    gets(infix);
    // Convert infix expression to postfix expression
    infixToPostfix();
    // Display the postfix expression
    printf("\n Postfix expression is %s", postfix);
}
