// Leetcode #343 - Integer break

#include<vector>
#include<limits.h>
#include<iostream>

using std::max;
using std::vector;
using std::endl;
using std::cout;

class Solution{
    public:
        int intBreak(int n){
            vector<int> dp(n+1, 0);
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= i; j++){
                    dp[i] = max(dp[i], (i - j) * j);
                    dp[i] = max(dp[i], dp[j] * (i - j));
                }
            }
            return dp[n];
        }
};

int main(){
    Solution soln;
    cout << soln.intBreak(2) << endl;
    cout << soln.intBreak(10) << endl;
    return 0;
}
