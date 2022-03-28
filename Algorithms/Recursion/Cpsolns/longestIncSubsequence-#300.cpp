// Leetcode #300 - Longest increasing subsequence

#include<iostream>
#include<vector>

using std::vector; using std::max;
using std::cout; using std::endl;

class Solution{
    private:
        int helper(vector<int>& nums, int pos, int last){
            int n = nums.size();
            // at last position in array
            if(pos == n) return 0;
            int l1 = 0, l2 = 0;
            if(nums[pos] > last) // increasing subsequence
                l1 = helper(nums, pos + 1, nums[pos]) + 1;
            l2 = helper(nums, pos + 1, last);
            return max(l1, l2);
        }
    public:
        int maxLen(vector<int>& nums){
            int maxLen = 0, n = nums.size();
            for(int i = 0; i < n-1; i++){
                // evaluate all possible solutions
                int len = helper(nums, i+1, nums[i]);
                maxLen = max(maxLen, len);
            }
            return maxLen + 1;
        }
};

int main(){
    Solution soln;
    vector<int> n = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> n1 = {0,1,0,3,2,3};
    vector<int> n2 = {7,7,7,7,7,7,7};
    cout << soln.maxLen(n) << endl;
    cout << soln.maxLen(n1) << endl;
    cout << soln.maxLen(n2) << endl;
    return 0;
}
