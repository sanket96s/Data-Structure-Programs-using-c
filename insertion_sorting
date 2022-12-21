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
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("\n Elements after sorting are : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
