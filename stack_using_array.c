#include <stdio.h>
#include <stdlib.h>
int i, size, top = -1;

void push(int *stack)
{

    if (top == size - 1)
    {
        printf("\n Stack is overflow");
    }
    else
    {
        top++;
        printf("\n Enter data : ");
        scanf("%d", &stack[top]);
    }
}

void pop(int *stack)
{
    if (top == -1)
    {
        printf("\n Stack is empty");
    }
    else
    {
        printf("\n %d deleted", stack[top]);
        top--;
    }
}

void peak(int *stack)
{
    if (top == -1)
    {
        printf("\n Stack is empty");
    }
    else
    {
        printf("\n Top element is : %d", stack[top]);
    }
}

void display(int *stack)
{
    int count = top;
    if (count == -1)
    {
        printf("\n Stack is empty");
    }
    else
    {
        printf("\n Data stored is : ");
        while (count != -1)
        {
            printf("%d ", stack[count]);
            count--;
        }
    }
}

void main()
{

    int choice;
    printf("\n Enter size of stack : ");
    scanf("%d", &size);
    int stack[size];
    while (1)
    {
        printf("\n 1.push \t 2.pop \t 3.peak \t 4.display");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&stack);
            break;

        case 2:
            pop(&stack);
            break;

        case 3:
            peak(&stack);
            break;

        case 4:
            display(&stack);
            break;

        default:
            printf("wrong choice");
            break;
        }
    }
}
