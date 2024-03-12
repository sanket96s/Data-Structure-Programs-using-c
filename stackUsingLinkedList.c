#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// Function to create a new node and push it onto the stack
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

// Function to display all elements of the stack
void display()
{
    struct node *point = NULL;
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

// Function to push an element onto the stack
void push()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter data to insert : ");
    scanf("%d", &nn->data);
    nn->next = top;
    top = nn;
    printf("\n Data inserted successfully");
}

// Function to pop an element from the stack
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
        printf("\n Data deleted successfully");
    }
    else
    {
        top = Delete->next;
        free(Delete);
        printf("\n Data deleted successfully");
    }
}

// Function to view the top element of the stack
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

int main()
{
    int noOfNodes, createdNodes = 0, choice;
    printf("\n Enter how many nodes you want to create : ");
    scanf("%d", &noOfNodes);
    // Creating the initial stack with user-defined number of nodes
    while (createdNodes < noOfNodes)
    {
        create();
        createdNodes++;
    }
    // Menu-driven loop for stack operations
    while (1)
    {
        printf("\n");
        printf("\n 1.push \n 2.pop \n 3.display \n 4.peak \n 5.exit");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        // Performing operations based on user choice
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

        case 5:
            return 0;

        default:
            printf("\n Wrong choice!");
        }
    }
    return 0;
}
