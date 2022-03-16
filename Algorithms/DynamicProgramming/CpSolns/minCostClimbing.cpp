// Leetcode #746 - Min cost climbing stairs

// Approach - bottom up dp
// 1. Add 0 to the last position of cost array
// 2. Start evaluating from the second last position
// 3. Make cost[i] be the minimum between making one or two jumps
// 4. The result will either be in the first or second position of array

#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::min;
using std::cout;
using std::endl;

class MinCost{
    public:
        int minClimb(vector<int> &cost){
            cost.push_back(0);
            int n = cost.size();
            for(int i = n-3; i >= 0; i--){
                cost[i] = min((cost[i] + cost[i+1]), (cost[i] + cost[i+2]));
            }
            return min(cost[0], cost[1]);
        }
};

int main(){
    MinCost soln;
    vector<int> cost = {10, 15, 20};
    vector<int> cost1 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << soln.minClimb(cost) << endl;
    cout << soln.minClimb(cost1) << endl;
    return 0;
}
