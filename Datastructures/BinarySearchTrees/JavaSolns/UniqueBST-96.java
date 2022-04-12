// Leetcode #96 - Unique Binary Search Trees

class UniqueBST{
    private int helper(int n, int[] dp){
        if(n == 0) return 1;
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];

        int sum = 0;
        for(int i = 1; i <= n; i++){
            // sum of left and right
            sum += helper(i - 1, dp) * helper(n - i, dp);
        }
        dp[n] = sum;
        return dp[n];
    }
    public int numTrees(int n){
        int[] dp = new int[n+1];
        Arrays.fill(dp, -1);
        return helper(n, dp); 
    }
}
