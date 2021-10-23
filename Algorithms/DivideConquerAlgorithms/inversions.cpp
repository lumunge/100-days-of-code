#include<iostream>
using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int merge(int arr[], int l, int mid, int r){
    int m1 = mid - l + 1;
    int m2 = r - mid;

    int arr1[m1];
    int arr2[m2];

    for(int i = 0; i < m1; i++)
        arr1[i] = arr[l + i];
    for(int i = 0; i < m2; i++)
        arr2[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;
    int count = 0;
    while(i < m1 && j < m2){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
            k++;
        }else{
            arr[k] = arr2[j];
            j++;
            k++;
            count = count + (mid - i);
        }
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
    return count;
}

int mergeSort(int arr[], int l, int r){
    int count = 0;
    if(l < r){
        int mid = (l+r) / 2;
        count += mergeSort(arr, l, mid);
        count += mergeSort(arr, mid+1, r);
        count += merge(arr, l, mid, r);
    }
    return count;
}

int main(){
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, n);
    cout << mergeSort(arr, 0, n-1) << endl;
    printArr(arr, n);
    return 0;
}

