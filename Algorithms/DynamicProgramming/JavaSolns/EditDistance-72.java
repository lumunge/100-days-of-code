// Leetcode #72 - Edit distance

class EditDistance{
    static int minDistance(String word1, String word2) {
        int r = word1.length(), c = word2.length();
        int[][] dp = new int[r+1][c+1];

        // fill first row
        for(int i = 0; i < r+1; i++)
            dp[i][0] = i;
        // fill first column
        for(int i = 0; i < c+1; i++)
            dp[0][i] = i;

        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                // get the diagonal in table
                if(word1.charAt(i-1) == word2.charAt(j-1))
                    dp[i][j] = dp[i-1][j-1];
                else // get min between up, left and diagonal
                    dp[i][j] = Math.min(dp[i][j-1],  Math.min(dp[i-1][j], dp[i-1][j-1])) + 1;
            }
        }
        // print dp array
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++)
                System.out.print(dp[i][j] + " ");
            System.out.println();
        }

        return dp[r][c];
    }
}
