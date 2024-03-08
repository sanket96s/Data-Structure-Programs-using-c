// Program to perform operations on array
// Operations are insertion, creation, deletion, and displaying

#include <stdio.h>

// Function to display elements of the array
void display(int *array, int size)
{
    int i;
    printf("\n The elements are: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

// Function to insert an element into the array
void insert(int *array, int size, int *no_elements)
{
    // Check if the array is full
    if (*no_elements == size)
    {
        printf("\n Array is full");
    }
    else
    {
        int data, i, position;
        printf("\n Enter index to insert data: ");
        scanf("%d", &position);
        // Check if the index is within bounds
        if (position >= size || position < 0)
        {
            printf("\n Out of bound position");
        }
        else
        {
            printf("\n Enter data to insert: ");
            scanf("%d", &data);
            // Shift elements to make space for the new element
            for (i = *no_elements - 1; i >= position; i--)
            {
                array[i + 1] = array[i];
            }
            array[position] = data;
            (*no_elements)++;
            printf("\n Element added successfully");
        }
    }
}

// Function to delete an element from the array
void delete(int *array, int size, int *no_elements)
{
    // Check if the array is empty
    if (*no_elements == 0)
    {
        printf("\n Array is empty");
    }
    else
    {
        int position;
        printf("\n Enter index to delete data: ");
        scanf("%d", &position);
        // Check if the index is within bounds
        if (position >= *no_elements || position < 0)
        {
            printf("\n Out of bound position");
        }
        else
        {
            // Shift elements to overwrite the deleted element
            for (int i = position; i < size - 1; i++)
            {
                array[i] = array[i + 1];
            }
            array[size - 1] = 0;
            (*no_elements)--;
            printf("\n Element deleted successfully");
        }
    }
}

int main()
{
    int i, size, no_elements, choice;
    printf("\n Enter size of array: ");
    scanf("%d", &size);
    int array[size];
    printf("\n Enter how many elements you want to add: ");
    scanf("%d", &no_elements);
    printf("\n Enter elements of array: ");
    for (i = 0; i < no_elements; i++)
    {
        scanf("%d", &array[i]);
    }
    for (i = no_elements; i < size; i++)
    {
        array[i] = 0;
    }
    // Menu-driven loop for performing array operations
    while (1)
    {
        printf("\n 1. Insert \n 2. Delete \n 3. Display \n 4. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(array, size, &no_elements);
            break;
        case 2:
            delete (array, size, &no_elements);
            break;
        case 3:
            display(array, size);
            break;
        case 4:
            // Exit the program
            return 0;
        default:
            printf("\n Wrong choice");
        }
    }
    return 0;
}
