// Leetcode #714 - Best time to buy and sell stock with transaction fee

#include<iostream>
#include<vector>
#include<climits>

using std::max;
using std::vector;
using std::cout;
using std::endl;

class Solution{
    public:
        int maxProfit(vector<int>& prices, int fee){
            int cash = 0, hold  = -prices[0];
            int n = prices.size();
            for(int i = 1; i < n; i++){
                // sell stock
                cash = max(cash, hold + prices[i] - fee);
                // buy stock
                hold = max(hold, cash - prices[i]);
            }
            return cash;
        }
};

int main(){
    Solution soln;
    vector<int> p = {1, 3, 2, 8, 4, 9}; int f = 2;
    vector<int> p1 = {1, 3, 7, 5, 10, 3}; int f1 = 3;
    cout << soln.maxProfit(p, f) << endl;
    cout << soln.maxProfit(p1, f1) << endl;
    return 0;
}
