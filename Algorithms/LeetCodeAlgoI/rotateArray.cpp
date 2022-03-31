#include<iostream>
#include<vector>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given an array, rotate the array to the right by k steps,
 * k is non-negative
 *
 * Sample:
 * Input: [1, 2, 3, 4, 5, 6, 7], k = 3
 * 1st Rotation: [7, 1, 2, 3, 4, 5, 6];
 * 2nd Rotation: [6, 7, 1, 2, 3, 4, 5];
 * 3rd Rotation: [5, 6, 7, 1, 2, 3, 4]; --> Output;
 */

class Solution {
public:
    void printArr(vector<int> nums){
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    //Solution 1
    vector<int> rotate(vector<int>& nums, int k) {
        vector<int> result;
        for(int i = nums.size()-1; i >= nums.size() - k; i--){
            result.insert(result.begin(), nums[i]);
        }
        for(int i = 0; i < nums.size() - k; i++){
            result.push_back(nums[i]);
        }
        return result;
    }
    //Solution 2
    void rotateArray(vector<int>& nums, int k){
        vector<int> result(nums.size());
        for(int i = 0; i < nums.size(); i++){
            result[(i+k) % nums.size()] = nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] = result[i];
        }
        return;
    }
};

int main(){
    Solution soln;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    //vector<int> result = soln.rotate(nums, 3);
    //soln.printArr(result);
    soln.rotateArray(nums, 3);
    soln.printArr(nums);
    return 0;
}
