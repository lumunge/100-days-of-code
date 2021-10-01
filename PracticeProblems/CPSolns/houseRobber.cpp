#include<iostream>
#include<vector>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given an integer array nums, representing the amount of money of each house, return
 * the maximum amount of money you can rob wihtout alerting police.
 * Constraint, Ajdacent houses have connected security systems that will alert police
 *
 * Sample:
 * Input: [1, 2, 3, 1];
 * Output: 4;
 * Input: [2, 1];
 * Output: 2
 */

class Solution{
    public:
        //Naive Recursion
        int rob(vector<int>& nums, int n){
            //base cases
            if(n == 0) return 0;
            if(n == 1) return nums[0];
            return max(rob(nums, n-1), rob(nums, n-2) + nums[n-1]);
        }
        //DP
        int robII(vector<int>& nums){
            //base cases
            int n = nums.size();
            if(n == 0) return 0;
            if(n == 1) return nums[0];
            int x = nums[0], y = max(x, nums[1]);
            for(int i = 2; i < n; i++){
                int temp = y;
                y = max(y,  x + nums[i]);
                x = temp;
            }
            return y;
        }
};

int main(){
    Solution soln;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << soln.robII(nums) << endl;
    return 0;
}
