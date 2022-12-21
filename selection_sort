#include <stdio.h>
void main()
{
    int n, i, j, temp, min;
    printf("\n Enter number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("\n Enter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("\n Elements after sorting are : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
