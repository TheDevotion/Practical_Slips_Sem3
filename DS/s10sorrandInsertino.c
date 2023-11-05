#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h> //imp.

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void displayArray(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Generate random elements in the array
    srand(time(0)); // Seed for random number generation   IMP
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate random numbers between 0 to 99
    }

    printf("Array before sorting: ");
    displayArray(arr, n);

    // Sort the array using Insertion Sort
    insertionSort(arr, n);

    printf("Array after sorting using Insertion Sort: ");
    displayArray(arr, n);

    getch();
    return 0;
}
