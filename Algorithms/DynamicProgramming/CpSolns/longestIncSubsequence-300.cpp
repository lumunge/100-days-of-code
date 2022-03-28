// Leetcode #300 - Longest increasing subsequence

#include<iostream>
#include<vector>
#include<limits.h>

using std::vector; using std::max;
using std::cout; using std::endl;

class Solution{
    public:
        int maxLen(vector<int>& nums){
            int n = nums.size();
            // fill dp array with 1s - for single number 1 is longest subsequence
            vector<int> dp(n+1, 1);
            int maxLen = 1;
            
            for(int i = 1; i < n; i++){
                for(int j = 0; j < i; j++){
                    if(nums[i] > nums[j]){ // testing incremental subsequence
                        dp[i] = max(dp[i], dp[j] + 1);
                        maxLen = max(dp[i], maxLen);
                    }
                }
            }

            // print actual dp array
            for(int i = 0; i < n; i++)
                cout << dp[i] << " ";
            cout << endl;

            return maxLen;
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

