#include <stdio.h>
#include <string.h>

int i, flag = 0, top = -1;
char expression[100];

// Function to push an element onto the stack
void push(int *stack, char ch)
{
    top++;
    stack[top] = ch;
}

// Function to pop an element from the stack
void pop()
{
    top--;
}

// Function to check the validity of parentheses in the expression
void check()
{
    char ch;
    int stack[strlen(expression)]; // Stack to store opening parentheses

    // Iterate through each character in the expression
    for (i = 0; i < strlen(expression); i++)
    {
        // If the character is an opening parenthesis, push it onto the stack
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            ch = expression[i];
            push(stack, ch);
        }
        // If the character is a closing parenthesis
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            // If the stack is empty, set the flag to indicate invalid expression
            if (top == -1)
            {
                flag = 1;
                break;
            }
            else
            {
                // If the top of the stack contains the corresponding opening parenthesis, pop it
                if (expression[i] == ')' && stack[top] == '(' || expression[i] == ']' && stack[top] == '[' || expression[i] == '}' && stack[top] == '{')
                {
                    pop();
                }
                // If not, set the flag to indicate invalid expression
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
}

// Main function
void main()
{
    // Prompt the user to enter the expression
    printf("\n Enter your expression : ");
    fgets(expression, sizeof(expression), stdin);

    // Print the expression entered by the user
    printf("\n expression entered is : ");
    puts(expression);

    // Check the validity of the expression
    check();

    // Print the result based on the flag and the state of the stack
    if (flag == 1 || top != -1)
    {
        printf("\n Expression is not valid");
    }
    else
    {
        printf("\n Expression is valid");
    }
}
