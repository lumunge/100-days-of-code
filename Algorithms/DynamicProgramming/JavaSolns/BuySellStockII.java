// Leetcode #122 - Best time to buy and sell stock II

class BuySellStock{
    static int stock(int[] nums){
        int n = nums.length, maxProfit = 0, currMax = Integer.MAX_VALUE;
        if(n == 1) return nums[0];
        for(int i = 0; i < n; i++){
            if(nums[i] < currMax) currMax = nums[i];
            if(nums[i] - currMax > 0){
                maxProfit += nums[i] - currMax;
                currMax = nums[i];
            }
        }
        return maxProfit;
    }

    public static void main(String[] args){
        int[] p1 = {7, 1, 5, 3, 6, 4};
        int[] p2 = {1, 2, 3, 4, 5};
        int[] p3 = {4};
        System.out.println(stock(p1));
        System.out.println(stock(p2));
        System.out.println(stock(p3));
    }
}
