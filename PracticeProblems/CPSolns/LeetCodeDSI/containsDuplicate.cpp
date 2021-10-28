#include<bits/stdc++.h>

/*
 * PROBLEM STATEMENT:
 * Given an array of number, return true if there are duplicates, false otherwise.
 * Sample:
 * Input: nums = [1, 2, 3, 1]
 * Output: true
 * 
 * Input: nums = [3, 6, 8, 0]
 * Output: false
 *
 * Approach:
 * 1. Sort the number array in ascending order.
 * 2. If current element is equal to next element return true, otherwise false.
 *
 */


class Solution{
    public:
        bool containsDuplicate(std::vector<int>& nums){
            std::sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size()-1; i++){
                if(nums[i] == nums[i+1])
                    return true;
            }
            return false;
        }
};

int main(){
    Solution soln;
    std::vector<int> nums = {1, 2, 3, 4};
    std::cout << soln.containsDuplicate(nums) << std::endl;
    return 0;
}

