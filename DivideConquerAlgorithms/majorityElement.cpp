#include<iostream>
#include<vector>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Check wheather an input sequence contains a majority element
 * Majority Element -> count(majorityElement) > len(arr) / 2;
 */

int counter(vector<int> arr, int l, int r, int n){
    int count = 0;
    for(int i = l; i < r; i++){
       if(arr[i] == n){
           count += 1;
       }
    }
    return count;
}

int getMajority(vector<int> arr, int l, int r){
    //base case
    if(l == r){
        return arr[l];
    }
    int mid = (l+r) / 2;
    int left = getMajority(arr, l, mid);
    int right = getMajority(arr, mid+1, r);
    
    cout << "Left = " << left << endl;
    cout << "Right = " << right << endl;
    cout << "-------------" << endl;

    if(left == right){
        return left;
    }
    if(counter(arr, l, mid, left) > counter(arr, mid+1, r, right)){
        return left;
    }else{
        return right;
    }
}


int main(){
    vector<int> arr;
    int n;
    int x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
    cout << getMajority(arr, 0, n-1) << endl;
    return 0;
}
