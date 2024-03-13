#include <stdio.h>
#include <stdlib.h>

int i, size, front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int *queue)
{
    if (front == size - 1)
    {
        printf("\n queue is overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0, rear = 0;
        printf("\n Enter data : ");
        scanf("%d", &queue[front]);
        printf("\n Data inserted successfully");
    }
    else
    {
        front++;
        printf("\n Enter data : ");
        scanf("%d", &queue[front]);
        printf("\n Data inserted successfully");
    }
}

// Function to remove an element from the queue
void dequeue(int *queue)
{
    if (front == -1 && rear == -1)
    {
        printf("\n queue is empty");
    }
    else if (front == rear)
    {
        printf("\n %d deleted", queue[rear]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\n %d deleted", queue[rear]);
        rear++;
    }
}

// Function to get the top element of the queue without removing it
void peak(int *queue)
{
    if (front == -1 && rear == -1)
    {
        printf("\n queue is empty");
    }
    else
    {
        printf("\n Top element is : %d", queue[front]);
    }
}

// Function to display all elements in the queue
void display(int *queue)
{
    int count = front;
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

// Main function
int main()
{
    int choice;
    printf("\n Enter size of queue : ");
    scanf("%d", &size);
    int queue[size];
    while (1)
    {
        printf("\n");
        printf("\n 1.enqueue \n 2.dequeue \n 3.peak \n 4.display \n 5.exit");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(queue);
            break;

        case 2:
            dequeue(queue);
            break;

        case 3:
            peak(queue);
            break;

        case 4:
            display(queue);
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
