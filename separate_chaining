#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct node
{
    int data;
    struct node *next;
};
struct node *head[TABLE_SIZE] = {NULL}, *c;
void insert()
{
    int i, key;
    printf("\n Enter a value to insert into hash table\n");
    scanf("%d", &key);
    i = key % TABLE_SIZE;
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = key;
    nn->next = NULL;
    if (head[i] == NULL)
    {
        head[i] = nn;
    }
    else
    {
        c = head[i];
        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = nn;
    }
}
void search()
{
    int key, index;
    printf("\n Enter the element to be searched\n");
    scanf("%d", &key);
    index = key % TABLE_SIZE;
    if (head[index] == NULL)
        printf("\n Element not found\n");
    else
    {
        for (c = head[index]; c != NULL; c = c->next)
        {
            if (c->data == key)
            {
                printf("\n Element found");
                break;
            }
        }
        if (c == NULL)
            printf("\n Element not found");
    }
}
void display()
{
    int i = 0;

    for (i = 0; i < TABLE_SIZE; i++)
    {
        printf("\n Entries at index %d\n", i);
        if (head[i] == NULL)
        {
            printf("No Hash Entry\n");
        }
        else
        {
            for (c = head[i]; c != NULL; c = c->next)
                printf("%d->", c->data);
        }
    }
}

void main()
{
    int opt, key, i;
    while (1)
    {
        printf("\n1. Insert\t 2. Display \t3. Search \t4.Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            exit(0);
        }
    }
}
