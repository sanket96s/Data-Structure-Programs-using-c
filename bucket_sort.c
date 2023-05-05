#include <stdio.h>
#include <stdlib.h>
#define NBUCKET 10
#define INTERVAL 1000

struct Node
{
    int data;
    struct Node *next;
};

void BucketSort(int *a, int n);
struct Node *InsertionSort(struct Node *list);
void print(int *a, int n);
int getBucketIndex(int value);

void BucketSort(int *a, int n)
{
    int i, j;
    struct Node **buckets;
    buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);
    for (i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = NULL;
    }
    for (i = 0; i < n; ++i)
    {
        struct Node *current;
        int pos = getBucketIndex(a[i]);
        current = (struct Node *)malloc(sizeof(struct Node));
        current->data = a[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }
    for (i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = InsertionSort(buckets[i]);
    }
    for (j = 0, i = 0; i < NBUCKET; ++i)
    {
        struct Node *node;
        node = buckets[i];
        while (node)
        {
            a[j++] = node->data;
            node = node->next;
        }
    }
    return;
}

struct Node *InsertionSort(struct Node *list)
{
    struct Node *k, *nodeList;
    if (list == 0 || list->next == 0)
    {
        return list;
    }
    nodeList = list;
    k = list->next;
    nodeList->next = 0;
    while (k != 0)
    {
        struct Node *ptr;
        if (nodeList->data > k->data)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }
        for (ptr = nodeList; ptr->next != 0; ptr = ptr->next)
        {
            if (ptr->next->data > k->data)
                break;
        }
        if (ptr->next != 0)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next;
            ptr->next->next = 0;
            continue;
        }
    }
    return nodeList;
}

int getBucketIndex(int value)
{
    return value / INTERVAL;
}

void print(int *a, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int n, i;
    printf("\n Enter number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("\n Enter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Initial array: ");
    print(&a, n);
    BucketSort(&a, n);
    printf("Sorted array: ");
    print(&a, n);
    return 0;
}
