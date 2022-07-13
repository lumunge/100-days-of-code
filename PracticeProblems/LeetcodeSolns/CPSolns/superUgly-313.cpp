class Solution{
    public:
        int nthSuperUglyNumber(int n, vector<int>& primes){
            int s = primes.size();
            int arr[s];
            long long int dp[n];
            long long int minimum;
            
            dp[0] = 1;
            for(int i = 0; i < s; i++)
                arr[i] = 0;
            
            for(int i = 1; i < n; i++){
                minimum = INT_MAX;
                for(int j = 0; j < s; j++)
                    minimum = min(minimum, dp[arr[j]] * primes[j]);
                dp[i] = minimum;
                for(int k = 0; k < s; k++){
                    if(minimum == dp[arr[k]] * primes[k])
                        arr[k]++;
                }
            }
            return dp[n-1];
        }
};
