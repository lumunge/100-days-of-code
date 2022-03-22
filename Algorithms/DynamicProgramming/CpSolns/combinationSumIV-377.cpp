// Leetcode #377 - Combination sum IV

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

class Solution{
        public:
            int combSum(vector<int>& nums, int target){
                unsigned long long dp[target + 1];
                dp[0] = 1;
                
                for(int i = 1; i <= target; i++){
                    dp[i] = 0;
                    for(int n : nums)
                        if(n <= i)
                            dp[i] += (unsigned long long)dp[i - n];
                }
                return dp[target];
            }
};

int main(){
    Solution soln;
    vector<int> n = {1, 2, 3}; int t = 4;
    vector<int> n1 = {9}; int t1 = 3;
    cout << soln.combSum(n, t) << endl;
    cout << soln.combSum(n1, t1) << endl;
    return 0;
}
