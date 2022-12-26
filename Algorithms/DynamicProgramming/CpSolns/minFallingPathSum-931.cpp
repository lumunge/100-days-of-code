// Leetcode #931 - Minimum falling path sum.

#include<iostream>
#include<limits.h>
#include<vector>

using std::vector;
using std::min;
using std::cout;
using std::endl;

class Solution{
    public:
        int minPath(vector<vector<int>> arr){
            int r = arr.size(), c = arr[0].size();
            vector<vector<int>> dp(r, vector<int>(c));
            // fill last row
            for(int i = 0; i < c; i++)
                dp[r-1][i] = arr[r-1][i];

            // bottom up
            for(int i = r - 2; i >= 0; i--){
                for(int j = 0; j < c; j++){
                    dp[i][j] = arr[i][j]; // initial
                    int mn = dp[i+1][j];
                    
                    if(j + 1 < c)
                        mn = min(mn, dp[i+1][j+1]);
                    if(j - 1 >= 0)
                        mn = min(mn, dp[i+1][j-1]);
                    // set path
                    dp[i][j] += mn;
                }
            }
            // get min
            int res = INT_MAX;
            for(int i = 0; i < c; i++)
                res = min(dp[0][i], res);
            return res;
        }
    };

int main(){
    Solution soln;
    vector<vector<int>> a = {{2,1,3},{6,5,4},{7,8,9}};
    vector<vector<int>> a1 = {{-19,57},{-40,-5}};
    cout << soln.minPath(a) << endl;
    cout << soln.minPath(a1) << endl;
    return 0;
}
