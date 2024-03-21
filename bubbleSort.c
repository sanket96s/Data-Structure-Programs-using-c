#include <stdio.h>

void main()
{
    int noOfElements, i, j, temp;

    // Ask user for the number of elements
    printf("\n Enter number of elements : ");
    scanf("%d", &noOfElements);

    // Declare an array of size 'n' to store the elements
    int array[noOfElements];

    // Ask user to input the elements
    printf("\n Enter the elements : ");
    for (i = 0; i < noOfElements; i++)
    {
        scanf("%d", &array[i]);
    }

    // Bubble sort algorithm to sort the elements in ascending order
    for (i = 0; i < noOfElements - 1; i++)
    {
        for (j = 0; j < noOfElements - 1 - i; j++)
        {
            // Swap adjacent elements if they are in the wrong order
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Display the sorted elements
    printf("\n Elements after sorting are : ");
    for (i = 0; i < noOfElements; i++)
    {
        printf("%d ", array[i]);
    }
}
