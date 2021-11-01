#include<iostream>
#include<vector>
#include<limits.h>

using std::vector;
using std::cout;
using std::endl;

/*
 * PROBLEM STATEMENT:
 * Given an array of prices where prices[i] is goven stock on ith day.
 * Return the maximum profit that can be made, otherwise return 0 if no profit can be made.
 *
 * Sample:
 * Input: prices = [7, 1, 5, 3, 6, 4]
 * Output: 5
 * Explanation: buy 1 sell 6, difference = 5
 *
 * Approach:
 * Get the maximum difference between the buying and selling stock.
 *
 * Brute Force:
 * Use two loops to go through the vector and make every possible subtraction provided j 
 * is greater than i meaning the selling price is greater than the buying price.
 * Return the largest of the subtraction which is the maximum profit.
 * Time compexity O(n)
 * Space Complexity O(1)
 *
 * Optimized Approach:
 * Using only one pass through the array maintain a minimum element and update the maximum
 * value based on the difference of the two. This will be the max profit.
 *
 * Time O(n) one pass through the vector.
 * Constant Space O(1), no extra space.
 *
 */

class Solution {
    public:
        //Brute force approach
        int maxProfitBrute(vector<int>& prices){
            int maxProfit = 0;
            for(int i = 0; i < prices.size() - 1; i++){
                for(int j = i+1; j < prices.size(); j++){
                    int profit = prices[j] - prices[i];
                    if(profit > maxProfit)
                        maxProfit = profit;
                }
            }
            return maxProfit;
        }
        //Optimized approach.
        int maxProfitOpt(vector<int>& prices){
            int maxProfit = 0;
            int min = INT_MAX;
            for(int i = 0; i < prices.size(); i++){
                if(prices[i] < min)
                    min = prices[i];
                else if(prices[i] - min > maxProfit)
                    maxProfit = prices[i] - min;
            }
            return maxProfit;
        }
};

int main(){
    Solution soln;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << soln.maxProfitOpt(prices) << endl;
    return 0;
}
