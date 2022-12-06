#include <stdio.h>
#include <stdlib.h>

void quicksort(int *arr, int low, int high) {
    // Check for empty or null array
    if (arr == NULL || low >= high) {
        return;
    }

    // Select pivot element
    int pivot = arr[(low + high) / 2];

    // Divide array into two partitions
    int i = low, j = high;
    while (i <= j) {
        // Find first element in left partition that is greater than or equal to pivot
        while (arr[i] < pivot) {
            i++;
        }

        // Find first element in right partition that is less than or equal to pivot
        while (arr[j] > pivot) {
            j--;
        }

        // Swap elements and move to next pair
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    // Recursively sort left and right partitions
    quicksort(arr, low, j);
    quicksort(arr, i, high);
}

int main() {
    // Initialize array to be sorted
    int arr[] = {5, 4, 9, 8, 7, 6, 0, 1, 3, 2};

    // Perform quicksort
    quicksort(arr, 0, 9);

    // Print sorted array
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

