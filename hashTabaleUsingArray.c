#include <stdio.h>
#include <stdlib.h>

int size, i, count = 0;

// Function for quadratic probing during insertion and searching
int quadratic_probe(int dataValue, int *hashTable, int insert)
{
    int key = dataValue % size; // Calculate initial key
    i = 1;                      // Initialize quadratic probing counter

    // Check if hash table is full during insertion
    if (insert && count == size)
        return -1; // Hash table is full

    // Quadratic probing loop
    while (hashTable[key] != -1)
    {
        // If searching and data is found, return index
        if (!insert && hashTable[key] == dataValue)
            return key; // Element found during search

        // Update key using quadratic probing
        key = (key + i * i) % size;
        i++;
    }

    // Return index of empty slot for insertion or not found during search
    return key;
}

// Function to insert data into the hash table
void insert(int *hashTable)
{
    int dataValue, key;
    printf("\nEnter data value to insert: ");
    scanf("%d", &dataValue);

    // Perform quadratic probing to find empty slot for insertion
    key = quadratic_probe(dataValue, hashTable, 1);
    if (key != -1)
    {
        hashTable[key] = dataValue; // Insert data at empty slot
        printf("\nData added successfully.\n");
        count++; // Increment count of elements in hash table
    }
    else
    {
        printf("\nHash table is full.\n");
    }
}

// Function to search for data in the hash table
void search(int *hashTable)
{
    int dataValue, key;
    printf("\nEnter data value to search: ");
    scanf("%d", &dataValue);

    // Perform quadratic probing to find data in hash table
    key = quadratic_probe(dataValue, hashTable, 0);
    if (key != -1 && hashTable[key] == dataValue)
    {
        printf("\nValue %d found at index %d.\n", dataValue, key);
    }
    else
    {
        printf("\nValue %d not found.\n", dataValue);
    }
}

// Main function
int main()
{
    int choice;
    printf("\nEnter the size of hash table: ");
    scanf("%d", &size);

    // Create hash table and initialize with -1 (indicating empty slot)
    int hashTable[size];
    for (int i = 0; i < size; i++)
    {
        hashTable[i] = -1;
    }

    // Menu-driven program for hash table operations
    while (1)
    {
        printf("\n");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(hashTable);
            break;

        case 2:
            search(hashTable);
            break;

        case 3:
            return 0;

        default:
            printf("\nWrong choice.\n");
            break;
        }
    }
    return 0;
}
