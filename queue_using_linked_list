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

void enqueue()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter data to insert : ");
    scanf("%d", &nn->data);
    nn->next = 0;
    front->next = nn;
    front = nn;
    count++;
}

void dequeue()
{
    struct node *Delete;
    Delete = rear;
    if (front == 0)
    {
        printf("\n queue is underflow");
    }
    else if (Delete->next == 0)
    {
        free(Delete);
        front = 0;
        count--;
    }
    else
    {
        rear = Delete->next;
        free(Delete);
        count--;
    }
}

void peak()
{
    if (front == 0)
    {
        printf("\n queue is underflow");
    }
    else
    {
        printf("\n top element is : %d", front->data);
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
        printf("\n 1.enqueue \t 2.dequeue \t 3.display \t 4.peak");
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

        default:
            printf("\n Wrong choice!");
        }
    }
}
