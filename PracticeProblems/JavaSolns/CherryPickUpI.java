import java.util.Arrays;

class CherryPickUpI{
    static int maxPickUp(int[][] grid){
        int row = grid.length;
        int[][] dp = new int[row][row];
        
        for(int[] n : dp)
            Arrays.fill(n, Integer.MIN_VALUE);
        
        dp[0][0] = grid[0][0];
        for(int i = 1; i <= 2*row-2; i++){
            int[][] dp2 = new int[row][row];
            for(int[] n : dp2)
                Arrays.fill(n, Integer.MIN_VALUE);
            int max = Math.max(0, i - (row - 1));
            int min = Math.min(row-1, i);
            for(int j = max; j <= min; j++){
                for(int k = max; k <= min; k++){
                    if(grid[j][i-j] == -1 || grid[k][i-k] == -1)
                        continue;
                    int prev = grid[j][i-j];
                    if(j != k)
                        prev += grid[k][i-k];
                    for(int c1 = j-1; c1 <= j; c1++)
                        for(int c2 = k - 1; c2 <= k; c2++)
                            if(c1 >= 0 && c2 >= 0)
                                dp2[j][k] = Math.max(dp2[j][k], prev + dp[c1][c2]);
                }
            }
            dp = dp2;
        }
        return Math.max(0, dp[row-1][row-1]);
    }

    public static void main(String[] args){
        int grid[][] = {{0,1,-1},{1,0,-1},{1,1,1}};
        System.out.println(maxPickUp(grid));
    }
}
