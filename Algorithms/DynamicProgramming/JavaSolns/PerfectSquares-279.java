// Leetcode #279 - Perfect squares

class PerfectSquares{
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        Arrays.fill(dp, n);
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                int sq = j * j;
                // square must be less than n
                if(i - sq < 0) break;
                // minimum between current and remaining value
                dp[i] = Math.min(dp[i], 1 + dp[i - sq]);
            }
        }
        // return last computed value
        return dp[n];
    }
}
