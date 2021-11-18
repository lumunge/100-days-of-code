#include<iostream>
#include<vector>
#include<limits.h>

using std::vector;
using std::cout;
using std::endl;
using std::min;

vector<int> store;

int helper(vector<int> arr, int start){
    if(start >= arr.size() - 1)
        return 0;
    if(store[start])
        return store[start];

    int minJumps = INT_MAX;
    for(int i = start + 1; i <= start + arr[start]; i++)
        minJumps = min(minJumps, 1 + helper(arr, i));
    
    return store[start] = minJumps;
}

int jump(vector<int> &arr){
    store = vector<int>(arr.size());
    return helper(arr, 0);
}

int main(){
    vector<int> arr = {2, 3, 1, 1, 4};
    cout << jump(arr) << endl;
    return 0;
}
