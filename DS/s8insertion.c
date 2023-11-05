#include <stdio.h>
#include <conio.h>

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

// Start at the second element in the array.
// Compare the current element to the element before it.
// If the current element is smaller than the element before it, swap their positions.
// Repeat steps 2 and 3 until you reach the beginning of the array.
// Move on to the next element in the array and repeat steps 2-4.
// This process continues until the entire array is sorted.

// Here is an example of how the function would sort the array [12, 11, 13, 5, 6]:

// Iteration 1:
// key = 11
// j = 0

// while (j >= 0 && arr[j] > key):
//     arr[j + 1] = arr[j]
//     j = j - 1

// arr[j + 1] = key

// The array now looks like: [11, 12, 13, 5, 6]

// Iteration 2:
// key = 13
// j = 1

// while (j >= 0 && arr[j] > key):
//     arr[j + 1] = arr[j]
//     j = j - 1

// arr[j + 1] = key

// The array now looks like: [11, 12, 13, 5, 6]

// Iteration 3:
// key = 5
// j = 2

// while (j >= 0 && arr[j] > key):
//     arr[j + 1] = arr[j]
//     j = j - 1

// arr[j + 1] = key

// The array now looks like: [5, 11, 12, 13, 6]

// Iteration 4:
// key = 6
// j = 3

// while (j >= 0 && arr[j] > key):
//     arr[j + 1] = arr[j]
//     j = j - 1

// arr[j + 1] = key

// The array is now sorted: [5, 6, 11, 12, 13]

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Sorted array in ascending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    getch();
    return 0;
}
