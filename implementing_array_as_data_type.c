// program to create array of required size and use only few size and displaying
#include <stdio.h>
#include <stdlib.h>

struct array
{
    int total_size;
    int used_size;
    int *ptr;
};

void createarry(struct array *a, int x, int y)
{
    (*a).total_size = x;
    (*a).used_size = y;
    int *ptr = (int *)malloc(x * sizeof(int));
}

void setarray(struct array *a)
{
    int n, i;
    for (i = 0; i < a->used_size; i++)
    {
        printf("\n enter %dth elemenet : ", i);
        scanf("%d", &n);
        a->ptr[i] = n;
    }
}

void display(struct array *a)
{
    int i;
    printf("\n the elements are : ");
    for (i = 0; i < a->used_size; i++)
    {
        printf("%d ", a->ptr[i]);
    }
}

void main()
{
    int tsize, usize;
    struct array a;
    printf("\n eneter total size os array : ");
    scanf("%d", &tsize);
    printf("\n enter used size of array : ");
    scanf("%d", &usize);
    createarry(&a, tsize, usize);
    setarray(&a);
    display(&a);
}
