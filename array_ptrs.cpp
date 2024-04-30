// Group: Diego Lopez, Denny Zhang, Santiago Orozco Buri

/**
 * @file array_ptrs.cpp
 * by Diego Lopez
 * This program uses bubble sort implementation
 * and various utility functions to solve
 * Source: https://www.geeksforgeeks.org/bubble-sort/
 */

#include <iostream>
using namespace std;

/*
Utility Function to swap two elements
*/
void swap(int *a, int *b) {
  int buffer = *a;
  *a = *b;
  *b = buffer;
}

/*
Overloaded Utility Function to swap two elements
*/
void swap(int **a, int **b) {
  int *buffer = *a;
  *a = *b;
  *b = buffer;
}

/*
Bubble Sort function for regular ints
*/
void bubbleSort(int arr[], int n) {
  int i, j;
  bool swapped;
  for (i = 0; i < n - 1; i++) {
    swapped = false;
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (swapped == false) {
      break;
    }
  }
  return;
}

/*
Bubble Sort function for pointers
*/
void bubbleSortPtr(int *arr[], int n) {
  int i, j;
  bool swapped;
  for (i = 0; i < n - 1; i++) {
    swapped = false;
    for (j = 0; j < n - i - 1; j++) {
      if (*arr[j] > *arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (swapped == false) {
      break;
    }
  }
  return;
}

/*
Utility function to print an array
*/
void printArr(int *arr[], int length) {
  for (int i = 0; i < length; i++) {
    cout << *(arr[i]) << " ";
  }
  cout << endl;
}

int main() {
  int my_ints[4];
  // Populate the array with values from user.
  for (int i = 0; i < 4; i++) {
    cout << "Enter value for index: " << i << ": ";
    cin >> my_ints[i];
  }

  int *my_ptrs[4];
  // Initialize pointers to corresponding elements.
  for (int i = 0; i < 4; i++) {
    my_ptrs[i] = &my_ints[i];
  }
  // Sort the addresses of the my_ptrs array in ascending order.
  bubbleSort(*my_ptrs, 4);
  printArr(my_ptrs, 4);

  // Sort the my_ptrs array based on the integers that are being pointed to
  bubbleSortPtr(my_ptrs, 4);
  printArr(my_ptrs, 4);

  return 0;
}
