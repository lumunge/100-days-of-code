// Leetcode #309 - Best time to buy and sell ctock with cooldown

#include<iostream>
#include<limits.h>
#include<vector>
#include<string.h>

using std::max;
using std::vector;
using std::cout;
using std::endl;

class Solution{
    private:
        int mem[5001];

        int helper(vector<int>&prices, int j, int n){
            int profit = 0;
            if(j >= n) return 0;
            if(mem[j] != -1) return mem[j];
            for(int i = j+1; i < n; i++){
                if(prices[j] < prices[i])
                    profit = max(profit, prices[i] - prices[j] + helper(prices, i+2, n));
            }
            profit = max(profit, helper(prices, j+1, n));
            mem[j] = profit;
            return profit;
        }
    public:
        int maxProfit(vector<int>& prices){
            int n = prices.size();
            memset(mem, -1, sizeof(mem));
            return helper(prices, 0, n);
        }

};

int main(){
    Solution soln;
    vector<int> p = {1, 2, 3, 0, 2};
    vector<int> p1 = {7, 1, 5, 3, 6, 4};
    vector<int> p2 = {7, 6, 5, 4, 2};
    cout << soln.maxProfit(p) << endl;
    cout << soln.maxProfit(p1) << endl;
    cout << soln.maxProfit(p2) << endl;
    return 0;
}
