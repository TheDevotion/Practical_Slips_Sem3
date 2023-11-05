// Write a ‘C’ program to create a random array of n integers. Accept a value x from
// user and use Binary search algorithm to check whether the number is present in array
// or not.
// (Students can accept sorted array or can use any sorting method to sort the array)


//DO binary seach from other


#include<bits/stdc++.h>
using namespace std; 

int bin_search(int arr[], int low, int high, int key) {

    if(low == high) {
        if(arr[low] == key) {
            return low;
        }
        else {
            return -1;
        }
    }
    else {
        int mid = (low+high)/2;

        if(key == arr[mid]) {
            return mid;
        }
        if(key < arr[mid]) {
            return bin_search(arr,low,(mid-1),key);
        }
        else {
            return bin_search(arr,(mid+1),high,key);
        }
    }
}
  

  int main() {

    int found = 1;


  
  int arr[] = {2,3,5,6,8,9,11,24,67,69,95};
  int n = sizeof(arr)/sizeof(arr[0]);

    // taking the key you want to find.
    int key;
    cin >> key;

    // setting low and high to the ends of array.
    int low = 0;
    int high = (n-1);


    int ans = bin_search(arr,low,high,key);

    if(ans == -1) {
        cout << "Element is not present in the array";
        return 0;
    }   
    cout << " Elment is at " << ans;
    return 0;
  }
