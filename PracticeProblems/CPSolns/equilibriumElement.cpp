#include<iostream>
using namespace std;
/*
 * PROBLEM STATEMENT:
 * Find the equilibrium element
 * Equilibrium element --> An element whose sum of its left elements is equal to sum of its
 * right elemets.
 * Sample: {0, -3, 5, -4, -2, 3, 1, 0} == -4
 *          0 + -3 + 5 == -2 + 3 + 2
 */

/*
 * Solution 1:
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
}*/

void equilibrium(int arr[], int n){
    int left[n];
    left[0] = 0;
    for(int i = 1; i < n; i++){
        left[i] = left[i-1] + arr[i - 1];
    }
    int right = 0;
    for(int i = n-1; i >= 0; i--){
        if(left[i] == right){
            cout << i << " ";
        }
        right += arr[i];
    }
}
    

int main(){
    int arr[] = {0, -3, 5, -4, -2, 3, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    equilibrium(arr, n);
    return 0;
}
