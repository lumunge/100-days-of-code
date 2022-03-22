class CoinChangeII{
    static int numWays(int[] coins, int amt){
        int r = coins.length + 1, c = amt + 1;
        int dp[][] = new int[r][c];

        // fill first column with 1s
        for(int i = 0; i <= r-1; i++)
            dp[i][0] = 1;

        // fill first row with 0s
        for(int i = 0; i <= c-1; i++)
            dp[0][i] = 0;

        // fill dp array
        for(int i = 1; i <= r-1; i++){
            for(int j = 1; j <= c-1; j++){
                // not include coin
                dp[i][j] = dp[i-1][j];
                if(coins[i-1] <= j)
                    // include coin - less than curr 
                    dp[i][j] += dp[i][j - coins[i-1]];
            }
        }
        return dp[r-1][c-1];
    }
    public static void main(String[] args){
        int[] c = {1, 2, 5}; int a = 5;
        int[] c1 = {2}; int a1 = 3;
        int[] c2 = {10}; int a2 = 10;
        int[] c3 = {5}; int a3 = 10;
        System.out.println(numWays(c, a));
        System.out.println(numWays(c1, a1));
        System.out.println(numWays(c2, a2));
        System.out.println(numWays(c3, a3));
    }
}
