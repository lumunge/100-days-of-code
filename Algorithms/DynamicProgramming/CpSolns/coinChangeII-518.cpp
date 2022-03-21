// Leetcode #518 - coin change 2



#include<vector>
#include<iostream>

using std::vector;
using std::cout; 
using std::endl;

class Solution{
    public:
        int numWays(vector<int>& coins, int amt){
            int r = coins.size() + 1, c = amt + 1;
            int dp[r][c];
            
            // fill first col with 1s
            for(int i = 0; i <= r-1; i++)
                dp[i][0] = 1;
            // fill first row with 0s
            for(int j = 0; j <= c-1; j++)
                dp[0][j] = 0;
            
            for(int i = 1; i <= r-1; i++){
                for(int j = 1; j <= c-1; j++){
                    // don't include coin
                    dp[i][j] = dp[i-1][j];
                    // include coin - but must be less
                    if(coins[i-1] <= j)
                        // therefore add previous and coins if we include curr coin
                        dp[i][j] = dp[i][j] + dp[i][j - coins[i-1]];
                    // otherwise just count coins if we dont include curr coin
                }
            }
            return dp[r-1][c-1];
        }
};
int main(){
    Solution soln;
    vector<int> c = {1, 2, 5}; int a = 5;
    vector<int> c1 = {2}; int a1 = 3;
    vector<int> c2 = {10}; int a2 = 10;
    vector<int> c3 = {5}; int a3 = 10;
    cout << soln.numWays(c, a) << endl;
    cout << soln.numWays(c1, a1) << endl;
    cout << soln.numWays(c2, a2) << endl;
    cout << soln.numWays(c3, a3) << endl;
    return 0;
}
