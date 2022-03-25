// Leetcode #279 - Perfect squares

#include<iostream>
#include<vector>
#include<limits.h>

using std::vector;
using std::min;
using std::cout;
using std::endl;

class Solution{
    public:
        int squares(int n){
            vector<int> dp(n+1, n);
            dp[0] = 0;
            
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= i; j++){
                    int sq = j * j;
                    // square must be less than n
                    if(i - sq < 0) break;
                    // minimum between current and remaining value
                    dp[i] = min(dp[i], 1 + dp[i - sq]);
                }
            }
            // return last computed value
            return dp[n];
        }
};

int main(){
    Solution soln;
    cout << soln.squares(13) << endl;
    cout << soln.squares(12) << endl;
    cout << soln.squares(50) << endl;
    return 0;
}
