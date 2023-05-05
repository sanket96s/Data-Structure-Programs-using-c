#include <stdio.h>
int size, i, j;

void lsearch(int *arr, int size)
{
    int element;
    printf("\n enter element to search : ");
    scanf("%d", &element);
    int s = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("\n element found");
            s++;
            break;
        }
    }
    if (s = 0)
    {
        printf("\n element not found");

    }
}

void bsearch(int *arr, int size)
{
    int element;
    printf("\n enter element to search : ");
    scanf("%d", &element);
    int mid, low = 0, high = size - 1, s = 0;
    while (s == 0)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            printf("\n element found");
            s++;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
        else
        {
            printf("\n element not found");
            s++;
        }
    }
}

void main()
{
    int choice, temp;
    printf("\n Enter a size of array : ");
    scanf("%d", &size);
    int arr[size];
    printf("\n Enter elements of array : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    while (1)
    {
        printf("\n 1.linear search \t 2.binary search");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            lsearch(&arr, size);
            break;

        case 2:
            bsearch(&arr, size);
            break;

        default:
            printf("\n wrong choice ! enter again ");
        }
    }
}
