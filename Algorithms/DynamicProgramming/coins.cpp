#include<iostream>
#include<limits.h>
#include<vector>

using std::vector;
using std::cout;
using std::endl;
using std::min;


vector<int> coins = {1, 3, 4};

// recursive
int minCoins(int n){
    vector<int> dp;
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int u = 1e9;
        for(int j = 1; j < i; j++){
            if(i - coins[j] < 0) continue;
            u = min(u, dp[i - coins[j]] + 1);
        }
        dp[i] = u;
    }
    return dp[n];
}

int main(){
    cout << 6 << " " << minCoins(6) << endl;
    //cout << 10 << " " << minCoins(10) << endl;
    //cout << 3 << " " << minCoins(3) << endl;
    //cout << 90 << " " << minCoins(90) << endl;
    return 0;
}
