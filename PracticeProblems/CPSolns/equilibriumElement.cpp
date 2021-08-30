#include<iostream>
using namespace std;

int addElements(int arr[], int n){
    int total = 0;
    for(int i = 0; i < n; i++){
        total += arr[i];
    }
    return total;
}

int addBackElements(int arr[], int n, int x){
    int backTotal = 0;
    for(int i = x+1; i < n; i++){
        backTotal += arr[i];
    }
    return backTotal;
}


void equilibrium(int arr[], int n, int x){
    for(int i = 0; i < n; i++){
        if(addElements(arr, i) == addBackElements(arr, n, i)){
            cout << i << endl;
        }
    }
}
int main(){
    int arr[] = {0, -3, 5, -4, -2, 3, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    equilibrium(arr, n, x);
    return 0;
}
