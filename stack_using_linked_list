#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void create()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter data : ");
    scanf("%d", &nn->data);
    if (top == 0)
    {
        top = nn;
        nn->next = 0;
    }
    else
    {
        nn->next = top;
        top = nn;
    }
}

void display()
{
    struct node *point = 0;
    point = top;
    if (point == 0)
    {
        printf("\n Stack is underflow");
    }
    else
    {
        printf("\n Data stored is : \n");
        while (point->next != 0)
        {
            printf("%d  ", point->data);
            point = point->next;
        }
        printf("%d", point->data);
    }
}

void push()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter data to insert : ");
    scanf("%d", &nn->data);
    nn->next = top;
    top = nn;
}

void pop()
{
    struct node *Delete;
    Delete = top;
    if (top == 0)
    {
        printf("\n Stack is underflow");
    }
    else if (Delete->next == 0)
    {
        free(Delete);
        top = 0;
    }
    else
    {
        top = Delete->next;
        free(Delete);
    }
}

void peak()
{
    if (top == 0)
    {
        printf("\n Stack is underflow");
    }
    else
    {
        printf("\n top element is : %d", top->data);
    }
}

void main()
{
    int n, a = 0, choice;
    printf("\n Enter how many nodes you want to create : ");
    scanf("%d", &n);
    while (a < n)
    {
        create();
        a++;
    }
    while (1)
    {
        printf("\n 1.push \t 2.pop \t 3.display \t 4.peak");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            peak();
            break;

        default:
            printf("\n Wrong choice!");
        }
    }
}
