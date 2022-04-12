// Leetcode #96 - unique binary search trees

class Solution{
    private:
        int helper(vector<int> &dp, int n){
            if(n == 0) return 1;
            if(n <= 2) return n;
            if(dp[n] != -1) return dp[n];
            int sum = 0;
            for(int i = 1; i <= n; i++)
                sum += helper(dp, i - 1) * helper(dp, n - i);
            dp[n] = sum;
            return dp[n];
        }
    public:
        int numTrees(int n){
            vector<int> dp(n+1, -1);
            return helper(dp, n);
        }
};
