// Leetcode #1137 - N-th Tribonacci number

class Tribonacci{
    static int nthTrib(int n){
        int dp[] = new int[n+1];
        if(n <= 1) return n;
        // initialize first three tribonacci numbers
        dp[0] = 0; dp[1] = 1; dp[2] = 1;
        for(int i = 3; i <= n; i++)
            // tribonacci n is sum of previous three value
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        // return nth trobinacci
        return dp[n];
    }
    public static void main(String[] args){
        for(int i = 20; i < 30; i++)
            System.out.println(nthTrib(i));
    }
}
