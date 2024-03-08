// Program to perform operations on array
// Operations are insertion, creation, deletion, and displaying

#include <stdio.h>

// Function to display elements of the array
void display(int *a, int no_elements) {
    int i;
    printf("\n The elements are: ");
    for (i = 0; i < no_elements; i++) {
        printf("%d ", a[i]);
    }
}

// Function to insert an element into the array
void insert(int *a, int size, int *no_elements) {
    // Check if the array is full
    if (*no_elements == size) {
        printf("\n Array is full");
    } else {
        int data, p;
        printf("\n Enter index to insert data: ");
        scanf("%d", &p);
        // Check if the index is within bounds
        if (p >= size || p < 0) {
            printf("\n Out of bound position");
        } else {
            printf("\n Enter data to insert: ");
            scanf("%d", &data);
            // Shift elements to make space for the new element
            for (int i = *no_elements - 1; i >= p; i--) {
                a[i + 1] = a[i];
            }
            a[p] = data;
            (*no_elements)++;
            printf("\n Element added successfully");
        }
    }
}

// Function to delete an element from the array
void delete (int *a, int size, int *no_elements) {
    // Check if the array is empty
    if (*no_elements == 0) {
        printf("\n Array is empty");
    } else {
        int p;
        printf("\n Enter index to delete data: ");
        scanf("%d", &p);
        // Check if the index is within bounds
        if (p >= *no_elements || p < 0) {
            printf("\n Out of bound position");
        } else {
            // Shift elements to overwrite the deleted element
            for (int i = p; i < *no_elements - 1; i++) {
                a[i] = a[i + 1];
            }
            (*no_elements)--;
            printf("\n Element deleted successfully");
        }
    }
}

int main() {
    int size, no_elements;
    printf("\n Enter size of array: ");
    scanf("%d", &size);
    int a[size];
    printf("\n Enter how many elements you want to add: ");
    scanf("%d", &no_elements);
    printf("\n Enter elements of array: ");
    for (int i = 0; i < no_elements; i++) {
        scanf("%d", &a[i]);
    }
    int ch;
    // Menu-driven loop for performing array operations
    while (1) {
        printf("\n 1. Insert \t 2. Display \t 3. Delete \t 4. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert(a, size, &no_elements);
                break;
            case 2:
                display(a, no_elements);
                break;
            case 3:
                delete (a, size, &no_elements);
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
