class Solution{
    public:
        int minDistance(string word1, string word2){
            int x = word1.length(), y = word2.length();
            vector<vector<int>> dp(x+1, vector<int> (y+1));
            for (int i = 0; i <= x; i++){
                for (int j = 0; j <= y; j++){
                    if (i == 0 || j == 0) continue;
                    if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }   
            int res = x + y - 2 * dp[x][y];
            return res;
        }
};
