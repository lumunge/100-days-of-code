#include<iostream>
#include<vector>
using namespace std;

/* PROBLEM STATEMENT:
 * Given a sorted array and a target value,
 * Return index of target is found else return index where it would be if it were inserted.
 *
 * Sample:
 * Input: nums = [1, 3, 5, 6], target = 5;
 * Output: 2
 *
 * Sample: 
 * Input: nums[1, 3, 5, 6], target = 2;
 * Output: 1
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;
        while(min <= max){
            int guess = (min + max) / 2;
            if(nums[guess] == target)
                return guess;
            else if(nums[guess] < target)
                min = guess + 1;
            else
                max = guess - 1;
        }
        return min;
    }
};

int main(){
    Solution soln;
    vector<int> nums = {1, 3, 5, 6};
    int target = 0;
    cout << soln.searchInsert(nums, target) << endl;
    return 0;
}
