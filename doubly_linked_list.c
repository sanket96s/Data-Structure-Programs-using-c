#include <stdio.h>
#include <stdlib.h>
int count = 0, i;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *temp = NULL;

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

void add()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    int p;
    i = 1;
    printf("\n Enter the position to insert data : ");
    scanf("%d", &p);
    if (p > count + 1)
    {
        printf("\n wrong position ");
    }
    else
    {
        printf("\n Enter data to insert : ");
        scanf("%d", &nn->data);
        nn->next = 0;
        nn->prev = 0;
        if (p == 1)
        {
            temp = head;
            nn->next = temp;
            temp->prev = nn;
            head = nn;
            count++;
        }
        else if (p == count + 1)
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
            while (i < p - 1)
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
    }
}

void delete ()
{
    struct node *Delete;
    int p;
    i = 1;
    printf("\n Enter the position to delete data : ");
    scanf("%d", &p);
    if (p > count)
    {
        printf("\n wrong position ");
    }
    else
    {
        if (p == 1)
        {
            Delete = head;
            Delete->next->prev = 0;
            head = Delete->next;
            free(Delete);
            count--;
        }
        else if (p == count)
        {
            temp = head;
            while (i < p - 1)
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
            while (i < p - 1)
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
    while (a != 0)
    {
        printf("\n 1.add \t 2.delete \t 3.display \t 4.no.of_nodes 5.end_program");
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
            printf("list have %d nodes : ", count);
            break;

        case 5:
            a = 0;
            break;

        default:
            printf("\n Wrong choice!");
        }
    }
}
