// Leetcode #62 - unique paths

#include<iostream>
#include<vector>

using std::vector;
using std::cout; using std::endl;

class Solution{
    public:
        int paths(int r, int c){
            vector<vector<int>> dp(r, vector<int>(c, 0));
            // fill edge column with 1s
            for(int i = 0; i < r; i++)
                dp[i][0] = 1;
            // fill edge row with 1s
            for(int j = 0; j < c; j++)
                dp[0][j] = 1;
            // storing values
            for(int i = 1; i < r; i++){
                for(int j = 1; j < c; j++)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            return dp[r-1][c-1];
        }
};

int main(){
    Solution soln;
    cout << soln.paths(3, 7) << endl;
    cout << soln.paths(3, 2) << endl;
    cout << soln.paths(10, 10) << endl;
}
