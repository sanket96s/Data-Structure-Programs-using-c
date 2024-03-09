#include <stdio.h>
#include <stdlib.h>

// Global variables
int count = 0, i;

// Node structure
struct node
{
    int data;
    struct node *next;
};

// Head and temp pointers
struct node *head = NULL;
struct node *temp = NULL;

// Function to create a node
void create()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
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
        temp = nn;
        count++;
    }
}

// Function to display the linked list
void display()
{
    i = 0;
    temp = head;
    printf("\n Nodes data stored is : \n");
    while (i < count)
    {
        printf("%d  ", temp->data);
        i++;
        temp = temp->next;
    }
}

// Function to add a node at a given position
void add()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    int position;
    i = 1;
    printf("\n Enter the position to insert data : ");
    scanf("%d", &position);
    if (position > count + 1)
    {
        printf("\n wrong position ");
    }
    else
    {
        printf("\n Enter data to insert : ");
        scanf("%d", &nn->data);
        nn->next = 0;
        if (position == 1)
        {
            nn->next = head;
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
            temp->next = nn;
            count++;
        }
    }
}

// Function to delete a node at a given position
void delete()
{
    struct node *Delete;
    int position;
    i = 1;
    printf("\n Enter the position to delete data : ");
    scanf("%d", &position);
    if (position > count)
    {
        printf("\n wrong position ");
    }
    else
    {
        if (position == 1)
        {
            Delete = head;
            head = Delete->next;
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
            free(Delete);
            count--;
        }
        printf("\n Data deleted Successfully");
    }
}

// Main function
int main()
{
    int noOfNodes, createdNode = 0, choice;
    printf("\n Enter how many nodes you want to create : ");
    scanf("%d", &noOfNodes);
    // Creating nodes
    while (createdNode < noOfNodes)
    {
        create();
        createdNode++;
    }
    // Menu-driven loop for performing linked list operations
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
            printf("list have %d nodes", count);
            break;

        case 5:
            return 0;

        default:
            printf("\n Wrong choice!");
        }
    }
    return 0;
}
