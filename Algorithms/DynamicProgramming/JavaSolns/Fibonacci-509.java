// Leetcode #509 - nth fibonacci number

class Fibonacci{
    static int nthFib(int n){
        int dp[] = new int[n+1];
        // first and second fibonacci are 0 and 1
        if(n <= 1) return n;
        // add first two in dp array
        dp[0] = 0; dp[1] = 1;
        // start from 2
        for(int i = 2; i <= n; i++)
            // fibonacci n is sum of previous two values
            dp[i] = dp[i-1] + dp[i-2];
        // return nth fib
        return dp[n];
    }
    public static void main(String[] args){
        for(int i = 20; i < 30; i++)
            System.out.println(nthFib(i));
    }
}
