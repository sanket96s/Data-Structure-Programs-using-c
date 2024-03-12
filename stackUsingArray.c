#include <stdio.h>
#include <stdlib.h>

int i, size, top = -1;

// Function to push an element onto the stack
void push(int *stack)
{
    // Checking if the stack is full
    if (top == size - 1)
    {
        printf("\n Stack is overflow");
    }
    else
    {
        top++;
        // Reading data from the user and pushing onto the stack
        printf("\n Enter data : ");
        scanf("%d", &stack[top]);
        printf("\n Data inserted successfully");
    }
}

// Function to pop an element from the stack
void pop(int *stack)
{
    // Checking if the stack is empty
    if (top == -1)
    {
        printf("\n Stack is underflow");
    }
    else
    {
        // Popping the top element from the stack
        printf("\n %d deleted", stack[top]);
        top--;
    }
}

// Function to peek at the top element of the stack
void peak(int *stack)
{
    // Checking if the stack is empty
    if (top == -1)
    {
        printf("\n Stack is underflow");
    }
    else
    {
        // Displaying the top element of the stack
        printf("\n Top element is : %d", stack[top]);
    }
}

// Function to display all elements of the stack
void display(int *stack)
{
    int count = top;
    // Checking if the stack is empty
    if (count == -1)
    {
        printf("\n Stack is underflow");
    }
    else
    {
        printf("\n Data stored is : ");
        // Displaying elements from top to bottom of the stack
        while (count != -1)
        {
            printf("%d ", stack[count]);
            count--;
        }
    }
}

int main()
{
    int choice;
    // Getting the size of the stack from the user
    printf("\n Enter size of stack : ");
    scanf("%d", &size);
    // Declaring the stack array
    int stack[size];
    // Menu-driven loop for stack operations
    while (1)
    {
        printf("\n");
        printf("\n 1.push \n 2.pop \n 3.peak \n 4.display \n 5.exit");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        // Performing operations based on user choice
        switch (choice)
        {
        case 1:
            push(stack);
            break;

        case 2:
            pop(stack);
            break;

        case 3:
            peak(stack);
            break;

        case 4:
            display(stack);
            break;

        case 5:
            return 0;

        default:
            printf("wrong choice");
            break;
        }
    }
    return 0;
}
