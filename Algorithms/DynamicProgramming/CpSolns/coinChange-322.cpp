// Leetcode #322 - coin change

#include<iostream>
#include<vector>
#include<limits.h>

using std::vector; using std::min;
using std::cout; using std::endl;

class Solution{
    public:
        int minCoins(vector<int>& coins, int amount){
            // create dp array and fill it with maximum
            vector<int> dp(amount + 1, amount + 1);
            // base case
            dp[0] = 0;
            
            for(int i = 1; i < amount+1; i++){
                for(int j : coins){
                    // i - current coin greater than 0
                    if(i - j >= 0)
                        // get minimum
                        dp[i] = min(dp[i], 1 + dp[i - j]);
                }
            }
            // not the set value - at the begining
            return dp[amount]  != amount + 1 ? dp[amount] : -1;
        }
};

int main(){
    Solution soln;
    vector<int> c = {1, 2, 5}; int a = 11;
    vector<int> c1 = {2}; int a1 = 3;
    vector<int> c2 = {1}; int a2 = 0;
    cout << soln.minCoins(c, a) << endl;
    cout << soln.minCoins(c1, a1) << endl;
    cout << soln.minCoins(c2, a2) << endl;
    return 0;
}
