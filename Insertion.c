#AAinclude <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void generateRandomArray(int arr[], int n, int max_value) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max_value; // Generate random numbers
    }
}

int main() {
    int n = 10000; // Size of the array
    int max_value = 10000; // Maximum value for random numbers
    int *arr = malloc(n * sizeof(int)); // Allocate memory for the array

    // Generate random array
    generateRandomArray(arr, n, max_value);

    // Start timing
    clock_t start = clock();
    
    // Sort the array
    insertionSort(arr, n);
    
    // End timing
    clock_t end = clock();

    // Calculate time taken in milliseconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printf("Time taken to sort %d elements: %.2f milliseconds\n", n, time_taken);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Free allocated memory
    return 0;
}
