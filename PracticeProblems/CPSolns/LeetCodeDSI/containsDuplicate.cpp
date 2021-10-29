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
 * Approach I:
 * 1. Sort the number array in ascending order.
 * 2. If current element is equal to next element return true, otherwise false.
 *
 * Approach II:
 * 1. use an unordered set.
 * 2. Initilize duplicate as false
 * 3. Use for loop to go through the nums vector
 * 4. For each element search it in the unordered set using find()
 * 5. If its in set, set duplicate to true otherwise insert it to set
 * 6. Return bool value of duplicate
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

        bool containsDuplicateII(std::vector<int>& nums){
            std::unordered_set<int> uset;
            bool dup = false;
            for(int i = 0; i < nums.size(); i++){
                if(uset.find(nums[i]) != uset.end())
                    dup = true;
                else
                    uset.insert(nums[i]);
            }
            return dup;
        }
};

int main(){
    Solution soln;
    std::vector<int> nums = {1, 2, 3, 1};
    std::cout << soln.containsDuplicateII(nums) << std::endl;
    return 0;
}
