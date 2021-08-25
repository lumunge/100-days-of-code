#include<iostream>
#include<time.h>
using namespace std;

//Helper functions
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
    int j = l;
    for(int i = l+1; i <= r; i++){
        if(arr[i] <= x){
            j++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[j], &arr[l]);
    return j;
}
/*
 * Quicksort with no randomized partitioning element
void quickSort(int arr[], int l, int r){
    if(l < r){
        //Partitioning Index
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}
*/
//Randomized quicksort -> Select random pivot 
//Time -> O(nlogn)
void quickSort(int arr[], int l, int r){
    if(l < r){
        srand(time(NULL));
        int k = l + rand() % (r-l);
        swap(&arr[l], &arr[k]);
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}
int main(){
    int arr[] = {8, 9, 5, 4, 1, 3, 10, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}
