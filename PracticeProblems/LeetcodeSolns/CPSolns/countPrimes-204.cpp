#define uint unsigned long int

class Solution {
    public:
        int countPrimes(int n){
            int count = 0;
            vector<bool> primes = vector(n+1, true);
            primes[0] = false;
            if(n > 0) primes[1] = false;
            for(uint i = 2; i <= n; i++){
                if(primes[i]){
                    for(uint j = i * i; j <= n; j += i)
                        primes[j] = false;
                }
            }
            for(uint i = 0; i < n; i++){
                if(primes[i]) count++;
            }
            return count;
        }
};
