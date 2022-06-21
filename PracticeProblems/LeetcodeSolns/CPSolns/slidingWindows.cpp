#include<iostream>
using std::cout;
using std::endl;

/*
 * PROBLEM STATEMENT:
 * Printing sliding window elements
 */

void printSlidingWindows(int arr[], int n, int k){
    for(int i = 0; i <= n-k; i++){
        int j;
        for(j = 0; j < k; j++){
            cout << arr[i+j] << " ";
        }
        cout << endl;
    }
}

// Driver code
int main(){
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    printSlidingWindows(arr, n, k);
    return 0;
}
