#include<iostream>
using namespace std;

int main(){
    int arr[] = {1, 7, 10, 15, 4, 5, 6, 4, 9, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        if(arr[i] <= 5){
            cout << arr[i] << " ";
            continue;
        }
    }
    return 0;
}
