// Leetcode #746 - Min cost climbing stairs

class MinCostClimbStairs{
    static int minCost(int[] cost){
        int n = cost.length;
        for(int i = n-3; i >= 0; i--)
            // we can climb 1/2 steps - get min between choosing the first and second step
            cost[i] = Math.min((cost[i] + cost[i+2]), (cost[i] + cost[i+1]));
        // bottom-up, return min between the first two values
        return Math.min(cost[0], cost[1]);
    }
    public static void main(String[] args){
        int[] c = {10, 15, 20};
        int[] c1 = {1,100,1,1,1,100,1,1,100,1};
        System.out.println(minCost(c));
        System.out.println(minCost(c1));
    }
}
