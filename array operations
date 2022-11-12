// program to perform operations on array
// operations are insertion ,creating ,deleting ,displaying
#include <stdio.h>

void display(int *a, int no_elements)
{
    int i;
    printf("\n the elements are : ");
    for (i = 0; i < no_elements; i++)
    {
        printf("%d ", a[i]);
    }
}

void insert(int *a, int size, int *no_elements)
{
    if (no_elements == size)
    {
        printf("\n array is full");
    }
    else
    {
        int data, p;
        printf("\n enter index to insert data : ");
        scanf("%d", &p);
        if (p > size)
        {
            printf("\n out of bound position");
        }
        else
        {
            printf("\n enter data to insert : ");
            scanf("%d", &data);
            for (int i = size - 1; i >= p; i--)
            {
                a[i + 1] = a[i];
            }
            a[p] = data;
            no_elements++;
            printf("\n element added succesfully");
        }
    }
}

void delete (int *a, int size, int *no_elements)
{
    if (no_elements == 0)
    {
        printf("\n array is empty");
    }
    else
    {
        int p;
        printf("\n enter index to delete data : ");
        scanf("%d", &p);
        if (p > size)
        {
            printf("\n out of bound position");
        }
        else
        {
            for (int i = p; i <= size; i++)
            {
                a[i] = a[i + 1];
            }
            no_elements--;
            printf("\n element deleted succesfully");
        }
    }
}

void main()
{
    int size, no_elements;
    printf("\n enter size of array : ");
    scanf("%d", &size);
    int a[size];
    printf("\n enter how many elements you want to add : ");
    scanf("%d", &no_elements);
    printf("\n enter elements of array : ");
    for (int i = 0; i < no_elements; i++)
    {
        scanf("%d", &a[i]);
    }
    int x = 1, ch;
    while (x > 0)
    {
        printf("\n 1.insert \t 2.display \t 3.delete: ");
        printf("\n enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:
            insert(&a, size, &no_elements);
            break;
        case 2:
            display(&a, no_elements);
            break;

        case 3:
            delete (&a, size, &no_elements);
            break;

        default:
            printf("\n wrong choice");
        }
    }
}
