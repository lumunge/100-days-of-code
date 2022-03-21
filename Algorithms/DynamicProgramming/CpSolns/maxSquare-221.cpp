// Leetcode #221 - Maximal square

#include<vector>
#include<iostream>
#include<limits.h>

using std::vector;
using std::min; using std::max;
using std::cout; using std::endl;

class Solution{
    public:
        int maxSq(vector<vector<char>>& grid){
            // matrix dimensions
            int r = grid.size(), c = grid[0].size();
            // dp array with padding filled with zeros
            vector<vector<int>> dp(r+1, vector<int>(c+1, 0));
            int max_sq = 0;
            
            for(int i = 1; i <= r; i++){
                for(int j = 1; j <= c; j++){
                    // cell must have a 1
                    if(grid[i-1][j-1] == '1'){
                       dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                        max_sq = max(max_sq, dp[i][j]); 
                    }
                }
            }
            return max_sq * max_sq;
        }
};

int main(){
    Solution soln;
    vector<vector<char>> g = {{'1','0','1','0','0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    vector<vector<char>> g1 = {{'0', '1'}, {'1', '0'}};
    vector<vector<char>> g2 = {{'0'}};
    cout << soln.maxSq(g) << endl;
    cout << soln.maxSq(g1) << endl;
    cout << soln.maxSq(g2) << endl;
    return 0;
}
