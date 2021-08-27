#include<iostream>
#include<time.h>
using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(int arr[], int l, int r){
    int j = l;
    for(int i = l; i < r; i++){
        if(arr[i] <= arr[r]){
            swap(arr[i], arr[j]);
            j++;
        }
    }
    swap(arr[r], arr[j]);
    return j;
}

/*
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
        swap(arr[l], arr[k]);
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

int main(){
    clock_t tStart = clock();
    int arr[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4, 6, 7, 7, 7, 7, 6, 6, 6, 9, 9, 9, 9, 9, 9, 9, 9,9, 9, 9, 1, 2, 6, 6, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printArr(arr, n);
    cout << "Time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
    //int x, y = threePartition(arr, 0, n-1);
    //cout << "X: " << x << "Y: " << y << endl;
    return 0;
}

