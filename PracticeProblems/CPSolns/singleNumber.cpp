#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given a non-empty array of intergers, every element appears twice except for one
 * find that single one
 *
 * Implement a solution with a linear time and constant space.
 *
 * Sample:
 * Input: nums = [2, 2, 1]
 * Output: 1;
 * Input: nums = [1]
 * Output: 1
 */

class Solution{
    public:
        //sorting and checking adjacent elements
        int singleNumber(vector<int>& nums){
            int n = nums.size();
            sort(nums.begin(), nums.end());
            int i = 0;
            while(i < n){
                if(nums[i] != nums[i+1])
                    return nums[i];
                i += 2;
            }
            if(n % 2 == 1)
                return nums[n-1];
            return -1;
        }
        // 2*SumOfUniqueElements - SumOfAllElements = number
        int singleNumberII(vector<int>& nums){
            set<int> unique;
            int uniqueCount = 0, total = 0;
            for(int i : nums){
                total += i;
                unique.insert(i);
            }
            for(int i : unique){
                uniqueCount += i;
            }
            return ((2*uniqueCount) -  total);
        }
        //Using stack
        int singleNumberIII(vector<int>& nums){
            int n = nums.size();
            sort(nums.begin(), nums.end());
            stack<int> stack;
            int j = 0;
            if(n == 0)
                return -1;
            if(n == 1)
                return nums[0];
            while(j < n){
                stack.push(nums[j]);
                if(stack.top() == nums[j+1]){
                    stack.pop();
                }else{
                    break;
                }
                j+=2;
            }
            return stack.top();
        }
};

int main(){
    Solution soln;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << soln.singleNumberIII(nums) << endl;
    return 0;
}
