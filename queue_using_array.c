#include <stdio.h>
#include <stdlib.h>
int i, size, f = -1, r = -1;

void enqueue(int *queue)
{
    if (f == size)
    {
        printf("\n queue is overflow");
    }
    else if (f == -1 && r == -1)
    {
        f = 0, r = 0;
        printf("\n Enter data : ");
        scanf("%d", &queue[f]);
    }
    else
    {
        f++;
        printf("\n Enter data : ");
        scanf("%d", &queue[f]);
    }
}

void dequeue(int *queue)
{
    if (f == -1 && r == -1)
    {
        printf("\n queue is empty");
    }
    else if (f == r)
    {
        printf("\n %d deleted", queue[r]);
        f = -1;
        r = -1;
    }
    else
    {
        printf("\n %d deleted", queue[r]);
        r++;
    }
}

void peak(int *queue)
{
    if (f == -1 && r == -1)
    {
        printf("\n queue is empty");
    }
    else
    {
        printf("\n Top element is : %d", queue[f]);
    }
}

void display(int *queue)
{
    int count = f;
    if (count == -1)
    {
        printf("\n queue is empty");
    }
    else
    {
        printf("\n Data stored is : ");
        while (count != -1)
        {
            printf("%d ", queue[count]);
            count--;
        }
    }
}

void main()
{

    int choice;
    printf("\n Enter size of queue : ");
    scanf("%d", &size);
    int queue[size];
    while (1)
    {
        printf("\n 1.enqueue \t 2.dequeue \t 3.peak \t 4.display");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&queue);
            break;

        case 2:
            dequeue(&queue);
            break;

        case 3:
            peak(&queue);
            break;

        case 4:
            display(&queue);
            break;

        default:
            printf("wrong choice");
            break;
        }
    }
}
