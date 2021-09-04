#include<iostream>
#include<vector>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given an unsorted interger array, find a pair with given sum in it.
 */

void printArr(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            if(nums[i] + nums[j] == target){
                result = {i, j};
            }
        }
    }
    return result;
}

int main(){
    vector<int> arr;
    vector<int> result;
    int n;
    int target;
    int x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
    cout << "Target: ", cin >> target;
    result = twoSum(arr, target);
    if(result.size() > 0){
        printArr(result);
    }else{
        cout << "Not Found!" << endl;
    }
    return 0;
}
