// Leetcode #304 - Range sum query 2D - immutable

class NumMatrix {
    private int dp[][] = new int[201][201];
    public NumMatrix(int[][] matrix) {
        int r = matrix.length, c = matrix[0].length;

        dp[0][0] = matrix[0][0];
        // fill first column
        for(int i = 1; i < r; i++){
            dp[i][0] = dp[i-1][0] + matrix[i][0];
        }
        // fill first row
        for(int i = 1; i < c; i++)
            dp[0][i] = dp[0][i-1] + matrix[0][i];    

        // fill middle
        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1] + matrix[i][j]) - dp[i-1][j-1];
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 != 0){
            return dp[row2][col2] - dp[row2][col1-1];
        }else if(row1 != 0 && col1 == 0){
            return dp[row2][col2] - dp[row1-1][col2];
        }else if(row1 == 0 && col1 == 0){
            return dp[row2][col2];
        }else{
            return dp[row2][col2] - dp[row2][col1 - 1] - dp[row1 - 1][col2] + dp[row1-1][col1-1];
        }
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
