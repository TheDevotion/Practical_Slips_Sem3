#include <stdio.h>

void bubble_sort(int arr[], int n) {
  // Sorts the given array in ascending order using the bubble sort algorithm.

  // Args:
  //   arr: A pointer to the array to be sorted.
  //   n: The number of elements in the array.

  // Returns:
  //   None.

  for (int i = n - 1; i >= 0; i--) {
    int didSwap = 0;

    for (int j = 0; j <= (i - 1); j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;

        didSwap = 1;
      }
    }

    if (didSwap == 0) {
      break;
    }
  }
}

int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  bubble_sort(arr, n);

  // printing sorted array:

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}