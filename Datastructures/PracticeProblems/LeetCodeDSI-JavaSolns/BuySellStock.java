//Leetcode 121

class BuySellStock{
    public static int maxProfit(int[] prices){
        int maxProfit = 0;
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < prices.length; i++){
            if(prices[i] < min)
                min = prices[i];
            else if(prices[i] - min > maxProfit)
                maxProfit = prices[i] - min;
        }
        return maxProfit;
    }

    public static void main(String[] args){
        int[] prices = {7,1,5,3,6,4};
        System.out.println(maxProfit(prices));
    }
}
