#include<iostream>
using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int l, int mid, int r){
    //Create two subarrays arr1 and arr2
    int m1 = mid - l + 1;
    int m2 = r - mid;

    int arr1[m1];
    int arr2[m2];

    for(int i = 0; i < m1; i++)
        arr1[i] = arr[l + i];
    for(int i = 0; i < m2; i++)
        arr2[i] = arr[mid + 1 + i];

    //Maintain indices of subarrays(i, j) and main array(k)
    int i = 0;
    int j = 0;
    int k = l;
    //Until we reach either end of arr1 or arr2 pick larger element among
    //elements in arr1 and arr2 and place them in correct position in main array
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
    //When we run out of elements in either arr1, or arr2
    //take the remaining elements and add them to remaining slots in main array
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
        merge(arr, l, mid, r);
    }
}

int main(){
    int arr[] = {2, 3, 9, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, n);
    mergeSort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}





