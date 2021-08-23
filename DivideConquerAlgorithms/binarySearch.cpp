#include<iostream>
#include<vector>
using namespace std;

//Returns index of target element
int binarySearch(vector<int> arr, int target){
    int max = arr.size() - 1;
    int min = 0;
    while(min <= max){
        int guess = (max + min) / 2;
        if(arr[guess] == target){
            return guess;
        }else if(arr[guess] < target){
            min = guess + 1;
        }else{
            max = guess - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr;
    int n;
    int target;
    int x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
    cout << "Target: ", cin >> target;
    cout << binarySearch(arr, target) << endl; 
    return 0;
}
