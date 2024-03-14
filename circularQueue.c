#include <stdio.h>
#include <stdlib.h>

// Global variables
int i, size, front = -1, rear = -1, count = 0;

// Function to enqueue an element into the circular queue
void enqueue(int *queue)
{
    // If the queue is full
    if (count == size)
    {
        printf("\n queue is overflow");
    }
    // If the queue is empty
    else if (front == -1 && rear == -1)
    {
        front = 0, rear = 0;
        printf("\n Enter data : ");
        scanf("%d", &queue[front]);
        count++;
        printf("\n Data inserted successfully");
    }
    // If the queue is neither full nor empty
    else
    {
        front = (front + 1) % size;
        printf("\n Enter data : ");
        scanf("%d", &queue[front]);
        count++;
    }
}

// Function to dequeue an element from the circular queue
void dequeue(int *queue)
{
    // If the queue is empty
    if (front == -1 && rear == -1)
    {
        printf("\n queue is empty");
    }
    // If there is only one element in the queue
    else if (front == rear)
    {
        printf("\n %d deleted", queue[rear]);
        front = -1;
        rear = -1;
        count--;
    }
    // If there are multiple elements in the queue
    else
    {
        printf("\n %d deleted", queue[rear]);
        rear = (rear + 1) % size;
        count--;
    }
}

// Function to get the front element of the circular queue
void peak(int *queue)
{
    // If the queue is empty
    if (front == -1 && rear == -1)
    {
        printf("\n queue is empty");
    }
    // If the queue is not empty
    else
    {
        printf("\n Top element is : %d", queue[front]);
    }
}

// Function to display all elements of the circular queue
void display(int *queue)
{
    int flag = rear;
    int temp = count;
    // If the queue is empty
    if (temp == 0)
    {
        printf("\n queue is empty");
    }
    // If the queue is not empty
    else
    {
        printf("\n Data stored is : ");
        while (temp != 0)
        {
            printf("%d ", queue[flag]);
            flag = (flag + 1) % size;
            temp--;
        }
    }
}

// Main function
int main()
{
    int choice;
    printf("\n Enter size of circular queue : ");
    scanf("%d", &size);
    int queue[size];
    // Menu-driven loop to interact with the circular queue
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
