#include<iostream>
using namespace std;

/*
 * Comparison-based algorithms
 * Each pair of adjacent elements is compared and elements swapped if not in order
 * Suitable for small datasets
 *
 * Sample:
 * 14, 9, 56, 11
 * 14, 9 --> swap --> 9, 14
 * 9, 14, 56, 11;
 * 9, 56
 * 56, 11 --> swap 11, 56
 * 14, 9, 11, 56
 *
 * 2nd Iteration
 * 14, 9 --> swap --> 9, 14
 * 9, 14, 11, 56
 * 14, 11 --> swap --> 11, 14
 * 9, 11, 14, 56 --> Sorted!!
 */

class BubbleSort{
public:
    void printArr(int arr[], int n){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void bubbleSort(int arr[], int n){
        for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
};

int main(){
    BubbleSort sort;
    int arr[] = {3, 67, 8, 11, 34, 65, 25, 99, 12, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort.printArr(arr, n);
    sort.bubbleSort(arr, n);
    sort.printArr(arr, n);
    return 0;
}
