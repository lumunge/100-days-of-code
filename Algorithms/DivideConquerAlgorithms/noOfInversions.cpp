#include<iostream>
using namespace std;


int inversions(int arr[], int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int arr[] = {2, 3, 9, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << inversions(arr, n) << endl;
    /*
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }*/
    return 0;
}
