#include<iostream>
#include<time.h>
using namespace std;

int getMin(int a, int b){
    return (a < b) ? a : b;
}
void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void merge(int arr[], int temp[], int l, int mid, int r, int n){
    int k = l;
    int i = l;
    int j = mid+1;
    while(i <= mid && j <= r){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i < n && i <= mid){
        temp[k] = arr[i];
        k++;
        i++;
    }
    for(int i = l; i <= r; i++){
        arr[i] = temp[i];
    }
}
void mergeSort(int arr[], int temp[], int l, int r, int n){
    for(int i = 1; i <= r-l; i *= 2){
        for(int j = l; j < r; j += j*2){
            int start = j;
            int mid = j + i - 1;
            int stop = getMin(j + 2*i - 1, r);
            merge(arr, temp, start, mid, stop, n);
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n], temp[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        arr[i] = temp[i] = (rand() % 50);
    }
    printArr(arr, n);
    mergeSort(arr, temp, 0, n-1, n);
    printArr(arr, n);
    return 0;
}
