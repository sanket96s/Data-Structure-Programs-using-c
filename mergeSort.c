#include <stdio.h>
#include <stdlib.h>

// Merge function to merge two sorted subarrays into one sorted array
void merge(int *arr, int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1; // Size of the left subarray
    int n2 = right - middle;    // Size of the right subarray

    // Temporary arrays to hold the elements of the left and right subarrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;    // Initial index of the left subarray
    j = 0;    // Initial index of the right subarray
    k = left; // Initial index of the merged subarray
    while (i < n1 && j < n2)
    {
        // Compare elements of both subarrays and merge them in sorted order
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(int *array, int left, int right)
{
    if (left < right)
    {
        // Calculate the middle index
        int middle = left + (right - left) / 2;

        // Sort the first and second halves recursively
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        // Merge the sorted halves
        merge(array, left, middle, right);
    }
}

// Main function
void main()
{
    int i, noOfElements;

    // Input the number of elements
    printf("\n Enter the number of elements : ");
    scanf("%d", &noOfElements);

    // Declare an array to store the elements
    int array[noOfElements];
    int left = 0, right = noOfElements - 1; // Initialize left and right indices

    // Input the elements
    printf("\n Enter the elements : ");
    for (i = 0; i < noOfElements; i++)
    {
        scanf("%d", &array[i]);
    }

    // Sort the array using merge sort
    mergeSort(array, left, right);

    // Display the sorted array
    printf("\nSorted array is \n");
    for (i = 0; i < noOfElements; i++)
    {
        printf("%d\t", array[i]);
    }
}
