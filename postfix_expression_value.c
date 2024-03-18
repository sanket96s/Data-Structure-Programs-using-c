#include <stdio.h>
#include <ctype.h>

// Global variables
int stack[100];
int top = -1, i = 0;
char expression[100];

// Function to push an element onto the stack
void push(int x)
{
    stack[++top] = x;
}

// Function to pop an element from the stack
int pop()
{
    return stack[top--];
}

// Function to evaluate the postfix expression
void answer()
{
    int num1, num2;
    char ch;

    // Iterate through each character of the postfix expression
    for (i = 0; expression[i] != '\0'; i++)
    {
        ch = expression[i];
        if (isdigit(ch))
        {
            // If the character is a digit, convert it to integer and push onto the stack
            ch = ch - 48; // Converting character digit to integer
            push(ch);
        }
        else
        {
            // If the character is an operator, pop two operands from the stack, perform operation, and push result back
            num1 = pop();
            num2 = pop();

            switch (ch)
            {
            case '+':
                push(num2 + num1);
                break;
            case '-':
                push(num2 - num1);
                break;
            case '*':
                push(num2 * num1);
                break;
            case '/':
                push(num2 / num1);
                break;
            }
        }
    }
    // Print the final answer
    printf("\n Answer is : %d", pop());
}

// Main function
void main()
{
    // Prompt the user to input a postfix expression
    printf("Enter the postfix expression (without spaces) : ");
    scanf("%s", expression);
    // Print the entered expression
    printf("\n Expression is : %s ", expression);
    // Evaluate the expression and print the result
    answer();
}
