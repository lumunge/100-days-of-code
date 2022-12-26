/* 
 * PROBLEM STATEMENT: Leetcode 221
 * Given a mxn matrix filled with 0s and 1s, find the largest square
 * containing only 1s and return its area.
 * 
 * Approach(dp).
 * Build a dp table and if dp[i-1][j-1] == '1'
 * Fill dp[i][j] with 1 + minimum(three directions(top, left, topleft)
 * Update the largest as you proceed.
 *  
 * Formula:
 * if(matrix[i-1][j-1] == '1')
 *     dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))
 *
 * Sample:
 * Input: [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Ouptut: 4
 *
 * Explanation;
 * Input Matrix;           Dp Matrix;
 * [1 0 1 0 0]          ["" 0 1 2 3 4 5]
 * [1 0 1 1 1] --->     [0  0 0 0 0 0 0] 
 * [1 1 1 1 1]          [1  0 1 0 1 0 0]
 * [1 0 0 1 0]          [2  0 1 0 1 1 1]
 *                      [3  0 1 1 1 2 2]  Largest = 2*2
 *                      [4  0 1 0 0 1 0]
 */

class MaximalSquare{
    static int maximalSquare(char[][] matrix){
       int r = matrix.length, c = matrix[0].length, msq = 0;
       int dp[][] = new int[r+1][c+1];
       if(r == 0 || c == 0) return 0;
       for(int i = 1; i < r; i++){
           for(int j = 1; j < c; j++){
               if(matrix[i-1][j-1] == '1'){
                   dp[i][j] = 1 + Math.min(dp[i-1][j], Math.min(dp[i][j-1], dp[i-1][j-1]));
                   if(dp[i][j] > msq)
                       msq = dp[i][j];
               }
           }
       }
       return msq;
    }

    public static void main(String args[]){
        char matrix[][] = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
        char matrix1[][] = {{'0','1'},{'1','0'}};
        System.out.println(maximalSquare(matrix));
        System.out.println(maximalSquare(matrix1));
    }
}
