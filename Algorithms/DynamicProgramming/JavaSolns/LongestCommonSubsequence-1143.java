// Leetcode 1143 - Longest common subsequence

class LongestCommonSubsequence{
    public int longestCommonSubsequence(String text1, String text2){
        int s = text1.length(), t = text2.length();
        int[][] dp = new int[s+1][t+1];
        int longest = 0;
        for(int i = 1; i < dp.length; i++){
            for(int j = 1; j < dp[i].length; j++){
                if(text1.charAt(i-1) == text2.charAt(j-1))
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j]);
                
                if(dp[i][j] > longest) longest = dp[i][j];
            }
        }
        return longest;
    }
}
