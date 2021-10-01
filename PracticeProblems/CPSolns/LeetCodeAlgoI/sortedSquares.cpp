#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given an interger array nums sorted in non-decreasing order,
 * return an array of squares of elements sorted in non-decreasing order
 *
 * Sample:
 * Input: [-4, -1, 0, 3, 10];
 * Squares: [16, 1, 0, 9, 100]
 * Output: [0, 1, 9, 16, 100];
 */

class Solution {
public:
    void printVector(vector<int> arr){
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            result.push_back(nums[i] * nums[i]);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution soln;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = soln.sortedSquares(nums);
    soln.printVector(result);
    return 0;
}
