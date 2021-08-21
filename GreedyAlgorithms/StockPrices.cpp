#include<iostream>
#include<vector>
using namespace std;

/*PROBLEM STATEMENT
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * Find the maximum profit you can achieve. 
 * You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 * You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 *
 * Sample:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 *              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 *          => If the array is in decreasing order no profit can be made return 0;
 */

int maxProfits(vector<int> prices){
    int maxProfit = 0;
    vector<int> profits;
    int n = prices.size();
    for(int i = 0; i < n-1; i++){
        profits.push_back(prices[i] - prices[i+1]);
    }   
    for(int i = 0; i < profits.size(); i++){
        if(profits[i] < 0){
            maxProfit += profits[i];
        }
    }
    return abs(maxProfit);
}

int main(){
    int n;
    vector<int> prices;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        prices.push_back(x);
    }
    cout << maxProfits(prices) << endl;
    return 0;
}
