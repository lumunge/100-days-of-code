// Leetcode 64 - Minimum path sum

#include<vector>
#include<limits.h>
#include<iostream>

using std::vector; using std::min;
using std::cout; using std::endl;

class Solution{
    public:
        int minPathSum(vector<vector<int>>& grid){
            // grid dimensions
            int r = grid.size(), c = grid[0].size();
            // dp vector with maximum
            vector<vector<int>> dp(r+1, vector<int>(c+1, INT_MAX));
            // last cell 
            dp[r-1][c] = 0;
            
            for(int i = r-1; i >= 0; i--){
                for(int j = c-1; j >= 0; j--){
                    // cell to bottom and cell to right
                    dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
                }
            }
            // bottom-up, return first cell
            return dp[0][0];
        }
};

int main(){
    Solution soln;
    vector<vector<int>> v = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> v1 = {{1, 2, 3}, {4, 5, 6}};
    cout << soln.minPathSum(v) << endl;
    cout << soln.minPathSum(v1) << endl;
    return 0;
}
