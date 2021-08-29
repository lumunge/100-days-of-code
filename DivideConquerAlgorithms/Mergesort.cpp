#include<iostream>
using namespace std;

void merge(int arr, int l, int r, int mid){
    int m1 = mid - l + 1;
    int m2 = r - mid;

    int arr1[m1];
    int arr2[m2];

    for(int i = 0; i < m1; i++)
        arr1[i] = arr[l + i];
    for(int i = 0; i < m2; i++)
        arr2[i] = arr[mid + 1 + j];
    
    int i = 0;
    int j = 0;
    int k = l;

    while(i < m1 && j < m2){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
        }else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < m1){
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j < m2){
        arr[k] = arr2[j];
        j++;
        k++;
    }

}
void mergeSort(int arr[], int l, int r){
    if(l < r){
        int mid = (l+r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, r, mid);
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, n);
    mergeSort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}
