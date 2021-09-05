#include<iostream>
using namespace std;

/*
 * INSERTION SORT ALGORITHM:
 * Iterate from arr[1] in array (key)
 * key = arr[i], j = i - 1
 * Shift elements to right while:
 *                      arr[j] > k && j >= 0;
 * Place key in its right position:
 *                                 arr[j+1] = k;
 */
class Sorting{
public:
    void printArr(int arr[], int n){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void insertionSort(int arr[], int n){
        int i, j, k;
        for(int i = 1; i < n; i++){
            k = arr[i];
            j = i - 1;
            while(j >= 0 && arr[j] > k){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = k;
        }
    }
};

int main(){
    Sorting sort;
    int arr[] = {9, 5, 1, 2, 13, 4, 6, 0, 90, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort.printArr(arr, n);
    sort.insertionSort(arr, n);
    sort.printArr(arr, n);
    return 0;
}
