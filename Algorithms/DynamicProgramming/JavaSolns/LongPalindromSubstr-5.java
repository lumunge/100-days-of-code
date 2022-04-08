// Leetcode #5 - Longest palindromic subsequence.

import java.util.Arrays;

class LongPalindromSubstr{
    public static String longest(String str){
        int n = str.length();
        boolean[][] dp = new boolean[n][n];
        // fill dp array
        //Arrays.fill(dp, false);

        for(int i = 0; i < n; i++) // fill diagonal - single characters
            dp[i][i] = true;
        
        // initialize pointers
        int l = 0, r = 1;
        for(int i = 0; i < n-1; i++){ // fill two characters
            if(str.charAt(i) == str.charAt(i+1)){
                dp[i][i+1] = true;
                // shift pointers
                l = 2;
                r = i;
            }
        }
        
        // start from third character
        for(int i = 3; i <= n; i++){
            for(int j = 0; j < n - i + 1; j++){
                int k = i + j - 1;
                if(dp[j+1][k-1] && str.charAt(j) == str.charAt(k)){
                    dp[j][k] = true;
                    if(i > l){
                        // reset pointers
                        l = j;
                        r = i;
                    }
                }
            }
        }
        return str.substring(l, r);
    }

    public static void main(String[] args){
        System.out.println(longest("babad"));
        System.out.println(longest("cbbd"));
    }
}
