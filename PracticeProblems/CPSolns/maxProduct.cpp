#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//soln 1
//Sort and compare the first two or the last two
//return the max product of the two

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
        if(arr[i] < arr[x]){
            j++;
            swap(&arr[x], &arr[j])
        }
    }
    swap(&arr[j], &arr[l]);
    return j;
}
void quickSort(int arr[], int l, int r){
    if(l < r){
        k = 

int main(){
    vector<int> arr;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << maxProduct(arr);
    return 0;
}
