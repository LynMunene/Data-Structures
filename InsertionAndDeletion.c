#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size);
void insertElement(int arr[], int *size, int element, int position);
void deleteElement(int arr[], int *size, int position);

int main()
    {
        int arr[MAX_SIZE] = {5, 25, 30, 40, 45};
        int size = 5;

        printf("Initial array: ");
        displayArray(arr, size);

        // Insert an element
        int element = 10;
        int position = 2;
        insertElement(arr, &size, element, position);

        printf("Array after insertion: ");
        displayArray(arr, size);

        // Delete an element
        position = 3;
        deleteElement(arr, &size, position);
        printf("Array after deletion: ");
        displayArray(arr, size);

        return 0;
    }

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insert an element at a specific position
void insertElement(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Error: Cannot insert, array is full!\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Error: Invalid position! Position must be between 0 and %d.\n", *size);
        return;
    }

    // Shift elements to the right
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*size)++;
}

// Function to delete an element at a specific position
void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Error: Invalid position! Position must be between 0 and %d.\n", *size - 1);
        return;
    }

    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}
