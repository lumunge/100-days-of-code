// Leetcode #714 - Best time to buy and sell stock with transaction fee

class BuySellStockFee{
     static int maxProfit(int[] prices, int fee) {
        int profit = 0, hold = -prices[0];
        int n = prices.length;
        for(int i = 1; i < n; i++){
            profit = Math.max(profit, hold + prices[i] - fee);
            hold = Math.max(hold, profit - prices[i]);
        }
        return profit;
    }

    public static void main(String[] args){
        int[] p = {1, 3, 2, 8, 4, 9};
        int[] p1 = {1, 3, 7, 5, 10, 3};
        System.out.println(maxProfit(p, 2));
        System.out.println(maxProfit(p1, 3));
    }
}
