// Leetcode #376 - Wiggle subsequence

#include<vector>
#include<iostream>

using std::vector; using std::max;
using std::cout; using std::endl;

class Solution{
    private:
        int helper(vector<int>& nums, int idx, bool wigl){
            int n = nums.size(); int maxLen = 0;
            for(int i = idx + 1; i < n; i++)
                // if up wiggle expect down, if down wiggle expect up
                if((wigl && nums[i] > nums[idx]) || (!wigl && nums[i] < nums[idx]))
                        maxLen = max(maxLen, helper(nums, i, !wigl) + 1);
            return maxLen;
        }
    public:
        int maxWiggle(vector<int>& nums){
            int n = nums.size();
            if(n < 2) return n;
            return max(helper(nums, 0, true), helper(nums, 0, false)) + 1;
        }
};

int main(){
    Solution soln;
    vector<int> n = {1,7,4,9,2,5};
    vector<int> n1 = {1,17,5,10,13,15,10,5,16,8};
    vector<int> n2 = {1,2,3,4,5,6,7,8,9};
    cout << soln.maxWiggle(n) << endl;
    cout << soln.maxWiggle(n1) << endl;
    cout << soln.maxWiggle(n2) << endl;
    return 0;
}
