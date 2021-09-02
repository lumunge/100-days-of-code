#include<iostream>
using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void moveZeros(int arr[], int n){
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            arr[j] = arr[i];
            j++;
        }
    }
    for(int i = j; i < n; i++){
        arr[i] = 0;
    }
    printArr(arr, n);
}

int main(){
    int arr[] = {5, 8, 0, 9, 0, 1, 0, 2, 0};
    int n = sizeof(arr) / sizeof(arr[n]);
    printArr(arr, n);
    moveZeros(arr, n);
    return 0;
}
