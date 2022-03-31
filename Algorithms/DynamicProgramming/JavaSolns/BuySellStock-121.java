// Leetcode #121 - Best time to buy and sell stock

class BuySellStock{
    static int profit(int[] prices){
        int n = prices.length;
        if(n < 2) return 0; // cannot transact
        int curr = Integer.MAX_VALUE, glob = 0;
        for(int p : prices){
            if(p < curr) curr = p; // minimim stock price
            if(p - curr > glob) glob = p - curr; // max profit
        }
        return glob;
    }
    static int profitI(int[] prices){
        int n = prices.length;
        if(n < 2) return 0; // cannot transact
        int maxProfit = Integer.MIN_VALUE, minStock = prices[0];
        for(int p : prices){
            maxProfit = Math.max(maxProfit, p - minStock); // get max profit
            minStock = Math.min(minStock, p); // reset min stock price
        }
        return maxProfit;
    }
    public static void main(String[] args){
        int[] p = {7,1,5,3,6,4};
        int[] p1 = {7,6,4,3,1};
        System.out.println(profit(p));
        System.out.println(profit(p1));
        System.out.println(profitI(p));
        System.out.println(profitI(p1));
    }
}
