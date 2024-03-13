#include <stdio.h>
#include <stdlib.h>

int count = 0;

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Function to create a new node and add it to the queue
void create()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter data : ");
    scanf("%d", &nn->data);
    nn->next = 0;
    if (front == 0)
    {
        front = nn;
        rear = nn;
        count++;
    }
    else
    {
        front->next = nn;
        front = nn;
        count++;
    }
}

// Function to display all elements in the queue
void display()
{
    struct node *point = 0;
    point = rear;
    if (count == 0)
    {
        printf("\n queue is underflow");
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

// Function to add an element to the queue
void enqueue()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter data to insert : ");
    scanf("%d", &nn->data);
    nn->next = 0;
    if (count == 0)
    {
        front = nn;
        rear = nn;
        count++;
    }
    else
    {
        front->next = nn;
        front = nn;
        count++;
    }
    printf("\n Data inserted successfully");
}

// Function to remove an element from the queue
void dequeue()
{
    struct node *Delete;
    Delete = rear;
    if (count == 0)
    {
        printf("\n queue is underflow");
    }
    else if (front == rear)
    {
        free(Delete);
        front = 0;
        rear = 0;
        count--;
        printf("\n Data deleted successfully");
    }
    else
    {
        rear = Delete->next;
        free(Delete);
        count--;
        printf("\n Data deleted successfully");
    }
}

// Function to get the top element of the queue without removing it
void peak()
{
    if (count == 0)
    {
        printf("\n queue is underflow");
    }
    else
    {
        printf("\n top element is : %d", front->data);
    }
}

// Main function
int main()
{
    int noOfNodes, createdNodes = 0, choice;
    printf("\n Enter how many nodes you want to create : ");
    scanf("%d", &noOfNodes);
    while (createdNodes < noOfNodes)
    {
        create();
        createdNodes++;
    }
    while (1)
    {
        printf("\n");
        printf("\n 1.enqueue \n 2.dequeue \n 3.display \n 4.peak \n 5.exit");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
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
