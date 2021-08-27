#include<iostream>
#include<time.h>
using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int threePartition(int arr[], int l, int r, int& i, int& j){
    if((r-l) <= 1){
        if(arr[r] < arr[l]){
            swap(arr[r], arr[l]);
        }
        i = l;
        j = r;
        return 0;
    }
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
    return i, j;
}

void quickSort(int arr[], int l, int r){
    if(l >= r)
        return;
    int m1, m2;
    threePartition(arr, l, r, m1, m2);
    quickSort(arr, l, m1);
    quickSort(arr, m2, r);
}

int main(){
    clock_t tStart = clock();
    int arr[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4, 6, 7, 7, 7, 7, 6, 6, 6, 9, 9, 9, 9, 9, 9, 9, 9,9, 9, 9, 1, 2, 6, 6, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printArr(arr, n);
    cout << "Time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
    return 0;
}
