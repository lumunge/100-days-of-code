// Leetcode #121 - Best time to but and sell stock.

#include<iostream>
#include<vector>
#include<limits.h>

using std::vector;
using std::endl;
using std::cout;

class Solution{
    public:
        int stock(vector<int>& nums){
            int maxProfit = 0, currMax = INT_MAX, n = nums.size();
            for(int i = 0; i < n; i++){
                if(nums[i] < currMax) currMax = nums[i];
                if(nums[i] - currMax > maxProfit) maxProfit = nums[i] - currMax;
            }
            return maxProfit;
        }
};

int main(){
    Solution soln;
    vector<int> p = {7, 1, 5, 3, 6, 4};
    vector<int> p1 = {7, 6, 4, 3, 1};
    vector<int> p2 = {1, 2, 3, 0, 2};
    cout << soln.stock(p) << endl;
    cout << soln.stock(p1) << endl;
    cout << soln.stock(p2) << endl;
}
