// Leetcode #322 - coin change

import java.util.Arrays

class CoinChange{
    public int coinChange(int[] coins, int amount) {
        // create dp array and fill it with maximum
        int[] dp= new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        // base case
        dp[0] = 0;
        
        for(int i = 1; i < amount+1; i++){
            for(int j : coins){
                // i - current coin greater than 0
                if(i - j >= 0)
                    // get minimum
                    dp[i] = Math.min(dp[i], 1 + dp[i - j]);
            }
        }
        // not the set value - at the begining
        return dp[amount]  != amount + 1 ? dp[amount] : -1;
    }
}
