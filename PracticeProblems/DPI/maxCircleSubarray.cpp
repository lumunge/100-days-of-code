// Leetcode #918 - Maximum sum circular subarray

#include<iostream>
#include<vector>
#include<limits.h>

using std::vector;
using std::cout; using std::endl;
using std::min; using std::max;

class Solution{
    public:
        int maxSum(vector<int>& arr){
            int total = 0;
            int maxEnding = 0, minEnding = 0;
            int maxSum = INT_MIN, minSum = INT_MAX;
            for(int x : arr){
                total += x;
                maxEnding = max(maxEnding + x, x);
                minEnding = min(minEnding + x, x);
                maxSum = max(maxSum, maxEnding);
                minSum = min(minSum, minEnding);
            }
            if(total > 0) return max(maxSum, total - minSum);
            return maxSum;
        }
};

int main(){
    Solution soln;
    vector<int> n1 = {1, -2, 3, -2};
    vector<int> n2 = {5, -3, 5};
    cout << soln.maxSum(n1) << endl;
    cout << soln.maxSum(n2) << endl;
    return 0;
}
