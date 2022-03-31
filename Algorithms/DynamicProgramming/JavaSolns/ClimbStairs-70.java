// Leetcode #70 - Climbing stairs

class ClimbStairs{
    static int climb(int n){
        int dp[] = new int[n+1];
        if(n <= 2) return n;
        // 0 ways for 0 steps, 1 way for 1 step, 2 ways for 2 steps
        dp[0] = 0; dp[1] = 1; dp[2] = 2;
        // start @ 3
        for(int i = 3; i <= n; i++)
            // we can climb 1/2 steps at a time - add previous two steps for ways to ith step
            dp[i] = dp[i-1] + dp[i-2];
        // return last dp value
        return dp[n];
    }
    public static void main(String[] args){
        for(int i = 5; i < 10; i++)
            System.out.println(climb(i));
    }
}
