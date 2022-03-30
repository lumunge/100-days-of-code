// Leetcode #72 - Edit distance

#include<iostream>
#include<vector>
#include<cstring>

using std::vector; using std::min; using std::string;
using std::cout; using std::endl;

class Solution{
    public:
        int minDist(string str1, string str2){
            int r = str1.length(), c = str2.length();
            vector<vector<int>> dp(r+1, vector<int> (c+1));
            
            // fill first row
            for(int i = 0; i < r+1; i++)
                dp[i][0] = i;
            // fill first column
            for(int i = 0; i < c+1; i++)
                dp[0][i] = i;
            
            for(int i = 1; i <= r; i++){
                for(int j = 1; j <= c; j++){
                    // get the diagonal in table
                    if(str1[i-1] == str2[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else // get min between up, left and diagonal
                        dp[i][j] = min(dp[i][j-1],  min(dp[i-1][j], dp[i-1][j-1])) + 1;
                }
            }
            /*
            // print dp array
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++)
                    cout << dp[i][j] << " ";
                cout << endl;
            }
            */
            
            return dp[r][c];
        }
};

int main(){
    Solution soln;
    string s = "horse", s1 = "ros";
    string s2 = "intention", s3 = "execution";
    string s4 = "", s5 = "";
    string s6 = "", s7 = "a";
    cout << soln.minDist(s, s1) << endl;
    cout << soln.minDist(s2, s3) << endl;
    cout << soln.minDist(s4, s5) << endl;
    cout << soln.minDist(s6, s7) << endl;
    return 0;
}
