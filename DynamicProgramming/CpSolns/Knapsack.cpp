#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class FractionalKnapsack{
public:
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity){
        vector<vector<int>> dp(profits.size(), vector<int>(capacity + 1, -1));
        return this->knapsack(dp, profits, weights, capacity, 0);
    }
private:
    int knapsack(vector<vector<int>> &dp, const vector<int> &profits, const vector<int> &weights, int capacity, int currentIndex){
        if(capacity <= 0 || currentIndex >= profits.size()){
            return 0;
        }
        if(dp[currentIndex][capacity] != -1){
            return dp[currentIndex][capacity];
        }
        int profit1 = 0;
        if(weights[currentIndex] <= capacity){
            profit1 = profits[currentIndex] + knapsack(dp, profits, weights, capacity - weights[currentIndex], currentIndex + 1);
        }
        int profit2 = knapsack(dp, profits, weights, capacity, currentIndex + 1);
        dp[currentIndex][capacity] = max(profit1, profit2);
        return dp[currentIndex][capacity];
    }
};

int main(){
    FractionalKnapsack knapsack;
    vector<int> profits = {1, 6, 10, 16};
    vector<int> weights= {1, 2, 3, 5};
    int capacity = 7;
    cout << knapsack.solveKnapsack(profits, weights, capacity) << endl;
    return 0;
}
