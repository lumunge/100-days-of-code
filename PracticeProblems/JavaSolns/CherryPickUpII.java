class CherryPickUpII{
    static int maxPickUp(int[][] grid){
        int row = grid.length;
        int col = grid[0].length;
        int dp[][][] = new int[row][col][col];

        for (int i = row - 1; i >= 0; i--) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < col; k++) {
                    int result = 0;
                    // current cell
                    result += grid[i][j];
                    if (j != k) {
                        result += grid[i][k];
                    }
                    if (i != row - 1) {
                        int max = 0;
                        for (int c1 = j - 1; c1 <= j + 1; c1++) {
                            for (int c2 = k - 1; c2 <= k + 1; c2++) {
                                if (c1 >= 0 && c1 < col && c2 >= 0 && c2 < col) {
                                    max = Math.max(max, dp[i + 1][c1][c2]);
                                }
                            }
                        }
                        result += max;
                    }
                    dp[i][j][k] = result;
                }
            }
        }
        return dp[0][0][col - 1];
    }
    public static void main(String[] args){
        int grid[][] = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
        System.out.println(maxPickUp(grid));
    }
}
