#include <stdio.h>
#include <stdlib.h>

// Function to create a dynamic 1D array
int* createDynamicArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return arr;
}

// Function to input elements into the array
void inputArray(int* arr, int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to print the array
void printArray(int* arr, int size) {
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = createDynamicArray(size);

    inputArray(arr, size);
    printArray(arr, size);

    free(arr);

    return 0;
}
