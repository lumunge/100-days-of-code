// Leetcode #309 - Best time to buy and sell stock with cooldown

class BuySellStockCool{
    // resursive dp
    private static int[] dp = new int[5001];

    private static int helper(int[] prices, int j, int n){
        if(j >= n) return 0; // out of bounds
        int profit = 0;
        //if(dp[j] != -1) return dp[j];
        for(int i = j + 1; i < n; i++){
            if(prices[j] < prices[i])
                profit = Math.max(profit, prices[i] - prices[j] + helper(prices, i+2, n));
        }
        profit = Math.max(profit, helper(prices, j+1, n));
        dp[j] = profit;
        return profit;
    }
    /*
    static int maxProfit(int[] prices){
        int n = prices.length;
        return helper(prices, 0, n);
    }*/

    static int maxProfit(int[] prices){
        int buy = Integer.MIN_VALUE, sell = 0, cool = 0;
        int n = prices.length;
        for(int i = 0; i < n; i++){
            int preBuy = buy, preSell = sell, preCool = cool;
            buy = Math.max(preBuy, preCool - prices[i]);
            sell = preBuy + prices[i];
            cool = Math.max(preCool, preSell);
        }
        return Math.max(sell, cool);
    }

    public static void main(String[] args){
        int[] p = {1, 2, 3, 0, 2};
        int[] p1 = {1};
        System.out.println(maxProfit(p));
        System.out.println(maxProfit(p1));
    }
}
