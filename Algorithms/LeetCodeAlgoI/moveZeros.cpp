#include<iostream>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given an arry move all zeros present in it to end while maintaining a relative order of elements
 */
void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Soln 1:
void moveZeros(int arr[], int n){
//If element is not zero place it in next available position in array
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            arr[j] = arr[i];
            j++;
        }
    }
//Add zeros to remaining part of the array
    for(int i = j; i < n; i++){
        arr[i] = 0;
    }
    printArr(arr, n);
}
//Soln2:
//Select 0 as pivot and partition the array based on pivot
void partition(int arr[], int n){
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main(){
    int arr[] = {5, 8, 0, 9, 0, 1, 0, 2, 0};
    int n = sizeof(arr) / sizeof(arr[n]);
    printArr(arr, n);
    partition(arr, n);
    printArr(arr, n);
    return 0;
}
