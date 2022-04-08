// Leetcode #64 - Minimum path sum

class MinPathSum{
    public int minPathSum(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        int[][] dp = new int[r+1][c+1];
        for (int[] row : dp)
            Arrays.fill(row, Integer.MAX_VALUE);
        
        dp[r-1][c] = 0;
        
        for(int i = r-1; i >= 0; i--){
            for(int j = c-1; j >= 0; j--){
                dp[i][j] = grid[i][j] + Math.min(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        return dp[0][0];
    }
}
