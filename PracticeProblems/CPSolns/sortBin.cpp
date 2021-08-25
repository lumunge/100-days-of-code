#include<iostream>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Sort an binary array
 * {1, 0, 1, 1, 0, 0, 0, 1} -> {0, 0, 0, 0, 1, 1, 1, 1}
 */

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* Count number of  zeros and fill part of the array with zero count
 * fill rest of array with ones
 *
void sortArr(int arr[], int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            count++;
        }
    }
    int k = 0;
    while(k < count){
        arr[k] = 0;
        k++;
    }
    while(count < n){
        arr[count+1] = 1;
        count++;
    }
}
*/


int main(){
    int arr[] = {1, 0, 1, 0, 1, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortArr(arr, n-1);
    printArr(arr, n);
    return 0;
}
