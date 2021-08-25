#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int l, int r){
    int x = arr[l];



int main(){
    int arr[] = {8, 6, 1, 3, 5, 10, 4, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortArr(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}
