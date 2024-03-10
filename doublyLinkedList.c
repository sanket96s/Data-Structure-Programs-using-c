#include <stdio.h>
#include <stdlib.h>

// Global variables for counting nodes and iterator
int count = 0, i;

// Define the structure for a doubly linked list node
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

// Declare head and temp pointers for the linked list
struct node *head = NULL;
struct node *temp = NULL;

// Function to create a new node and add it to the end of the list
void create()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->prev = 0;
    nn->next = 0;
    printf("\n Enter data : ");
    scanf("%d", &nn->data);
    if (head == 0)
    {
        head = temp = nn;
        count++;
    }
    else
    {
        temp->next = nn;
        nn->prev = temp;
        temp = nn;
        count++;
    }
}

// Function to display the contents of the list
void display()
{
    i = 0;
    temp = head;
    printf("\n Data stored is : \n");
    while (i < count)
    {
        printf("%d  ", temp->data);
        i++;
        temp = temp->next;
    }
}

// Function to add a node at a specified position in the list
void add()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    int position;
    i = 1;
    printf("\n Enter the position to insert data : ");
    scanf("%d", &position);
    if (position > count + 1 || position < 1)
    {
        printf("\n wrong position ");
    }
    else
    {
        printf("\n Enter data to insert : ");
        scanf("%d", &nn->data);
        nn->next = 0;
        nn->prev = 0;
        if (position == 1)
        {
            temp = head;
            nn->next = temp;
            temp->prev = nn;
            head = nn;
            count++;
        }
        else if (position == count + 1)
        {
            temp = head;
            while (temp->next != 0)
            {
                temp = temp->next;
            }
            temp->next = nn;
            nn->prev = temp;
            temp = nn;
            count++;
        }
        else
        {
            temp = head;
            while (i < position - 1)
            {
                temp = temp->next;
                i++;
            }
            nn->next = temp->next;
            nn->prev = temp;
            temp->next = nn;
            nn->next->prev = nn;
            count++;
        }
        printf("\n Data inserted successfully");
    }
}

// Function to delete a node from the list at a specified position
void delete()
{
    struct node *Delete;
    int position;
    i = 1;
    printf("\n Enter the position to delete data : ");
    scanf("%d", &position);
    if (position > count || position < 1)
    {
        printf("\n wrong position ");
    }
    else
    {
        if (position == 1)
        {
            Delete = head;
            Delete->next->prev = 0;
            head = Delete->next;
            free(Delete);
            count--;
        }
        else if (position == count)
        {
            temp = head;
            while (i < position - 1)
            {
                temp = temp->next;
                i++;
            }
            Delete = temp->next;
            temp->next = 0;
            free(Delete);
            count--;
        }
        else
        {
            temp = head;
            while (i < position - 1)
            {
                temp = temp->next;
                i++;
            }
            Delete = temp->next;
            temp->next = Delete->next;
            Delete->next->prev = temp;
            free(Delete);
            count--;
        }
        printf("\n Data deleted successfully");
    }
}

// Main function to control the flow of the program
int main()
{
    int noOfNodesToCreate, createdNodes = 0, choice;
    printf("\n Enter how many nodes you want to create : ");
    scanf("%d", &noOfNodesToCreate);
    while (createdNodes < noOfNodesToCreate)
    {
        create();
        createdNodes++;
    }
    while (1)
    {
        printf("\n");
        printf("\n 1.add \n 2.delete \n 3.display \n 4.no.of_nodes \n 5.end_program");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add();
            break;

        case 2:
            delete ();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\n list have %d nodes", count);
            break;

        case 5:
            return 0;

        default:
            printf("\n Wrong choice!");
        }
    }
    return 0;
}
