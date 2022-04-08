// Leetcode #62 - Unique paths

class UniquePaths{
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        // fill edge column with 1s
        for(int i = 0; i < m; i++)
            dp[i][0] = 1;
        // fill edge row with 1s
        for(int j = 0; j < n; j++)
            dp[0][j] = 1;
        // storing values
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        return dp[m-1][n-1];
    }
}
