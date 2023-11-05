// C program to evaluate given polynomial using function. ( Use array)

#include<stdio.h>
#include<conio.h>
#include<math.h>

void displayPoly(int arr[], int n) {
	int i;

	for(i=n; i>0; i--) {
		if(arr[i] != 0 ) {
			printf("%dX^%d + ",arr[i],i);
		}
	}
	printf("%d\n", arr[i]);
}
int evalPoly(int arr[], int n, int x){
	int i;
	int ans = 0;

	for(i=n; i>0; i--) {
		if(arr[i] != 0 ) {
			ans = ans + ( pow(x,i) * arr[i]);
		}
	}
	ans = ans + arr[i];

	return ans;

}


void main() {
	int i,n,ans,x,arr[20];

	clrscr();

	for(i=0; i<20; i++) {
		arr[i] = 0;
	}

	printf("Give the degree of the polynomial: ");
	scanf("%d", &n);

	printf("Give the coefficients of the polynomial equation:");
	for(i=n; i>=0; i--) {
		scanf("%d", &arr[i]);
	}
	printf("Given Polynomial is: \n ");
	displayPoly(arr,n);

	printf("Give value of X to evaluate the Polynomial:");
	scanf("%d", &x);

	ans = evalPoly(arr,n,x);
	printf("for x = %d  result of polynomial becomes: %d",x,ans);

	getch();

}

