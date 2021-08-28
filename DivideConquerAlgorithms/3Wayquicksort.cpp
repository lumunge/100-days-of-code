#include<iostream>
using namespace std;

/* PROBLEM STATEMENT
 * Implementation of a three way partition procedure
 */

void threePartition(int arr[], int l, int r, int &i, int &j){
    if(r - l <= 1){
        swap(arr[r], arr[l]);
    }
    i = l;
    j = r;
    int mid = l;
    int pivot = arr[r];
    while(mid <= r){
        if(arr[mid] < pivot){
            swap(arr[l], arr[mid]);
            l++;
            mid++;
        }else if(arr[mid] == pivot){
            mid++;
        }else{
            swap(arr[mid], arr[r]);
            r--;
        }
    }
    i = l - 1;
    j = mid;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int i, j;
        threePartition(arr, l, r, i, j);
        quickSort(arr, l, i);
        quickSort(arr, j, r);
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {4, 9, 4, 3, 1, 9, 4, 3, 9, 4, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, n);
    quickSort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}
