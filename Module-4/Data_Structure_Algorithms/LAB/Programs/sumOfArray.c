#include <stdio.h>

// Function that calculates the sum of an array of integers
int sum(int *arr, int size) {
  int total = 0;

  // Add each element in the array to the total
  for (int i = 0; i < size; i++) {
    total += arr[i];
  }

  return total;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  printf("\nSize of array %d", sizeof(arr)); 
  printf("\nSize of array[0] %d", sizeof(arr[0]));
  

  // Calculate the sum of the array using the sum() function
  int total = sum(arr, arr_size);

  printf("\nThe sum of the array is: %d\n", total);

  return 0;
}

