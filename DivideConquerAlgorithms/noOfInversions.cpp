#include<iostream>
using namespace std;


int main(){
    int arr[] = {2, 3, 9, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int q = partition(arr, 0, n-1);
    cout << "Q " << q << endl;
    /*
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }*/
    return 0;
}
