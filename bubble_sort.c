#include <stdio.h>
void main()
{
    int n, i, j, temp;
    printf("\n Enter number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("\n Enter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\n Elements after sorting are : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
