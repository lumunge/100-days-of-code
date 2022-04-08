// Leetcode #1314 - Matrix block sum

class MatrixBlockSum{
    private int[][] buildMatrix(int[][] mat){
            int r = mat.length, c = mat[0].length;
            int[][] dp = new int[201][201];
            dp[0][0] = mat[0][0];
            // fill first column
            for(int i = 1; i < r; i++)
                dp[i][0] = dp[i-1][0] + mat[i][0];
            
            // fill first row
            for(int i = 1; i < c; i++)
                dp[0][i] = dp[0][i-1] + mat[0][i];
            
            // fill middle area
            for(int i = 1; i < r; i++){
                for(int j = 1; j < c; j++)
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1] + mat[i][j]) - dp[i-1][j-1];
            }
            
            return dp;
        }
    public int[][] matrixBlockSum(int[][] mat, int k) {
        int r = mat.length, c = mat[0].length;
            int[][] dp = buildMatrix(mat);
            int[][] block = new int[r][c];

            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    int r1 = i - k - 1;
                    int c1 = j - k - 1;

                    int r2 = Math.min(r-1, i + k);
                    int c2 = Math.min(c-1, j + k);
                    int d = dp[r2][c2];

                    int a = (r1 >= 0 && c1 >= 0) ? dp[r1][c1] : 0;
                    int b = (r1 >= 0) ? dp[r1][c2] : 0;
                    int c_ = (c1 >= 0) ? dp[r2][c1] : 0;

                    block[i][j] = (a - b - c_) + d;
                }
            }

            return block;
    }
}
