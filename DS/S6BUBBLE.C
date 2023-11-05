/*
Write a C program to accept and sort n elements in ascending order
by using bubble sort.
*/

#include<stdio.h>
#include<conio.h>

void bubbleSort(int arr[], int n){
	int i,j,temp;

	// for first loop we are going till last index.
	// then we are reducing it by 1. every single time..
	// which means i is decreasing.

	for(i=n-1; i>0; i--) {

		// for this inner loop we are always going from j=0 till i-1 th index.
		for(j=0; j<i; j++) {

			if(arr[j] >= arr[j+1]) {
				//swap adjacent elements.
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}


void main() {
	int arr[20];
	int n,i;

	clrscr();

	printf("How many elements you want to sort?\n");
	scanf("%d",&n);

	printf("Give elements:\n");
	for(i=0; i<n;i++){
		scanf("%d", &arr[i]);
	}
	bubbleSort(arr,n);
	printf("Sorted array is:\n");
	for(i=0; i<n; i++) {
		printf("%d\t",arr[i]);
	}
	getch();
}








