// Leetcode #198 - House robber

#include<iostream>
#include<vector>

using std::vector;
using std::max;
using std::cout;
using std::endl;

class Solution{
    public:
        int rob(vector<int>& nums) {
            int max1 = 0, max2 = 0;
            for(int n : nums){
                int temp = max(max1+n, max2);
                max1 = max2;
                max2 = temp;
            }
            return max2;
        }
};

int main(){
    Solution soln;
    vector<int> n = {1, 2, 3, 1};
    vector<int> n1 = {2, 7, 9, 3, 1};
    cout << soln.rob(n) << endl;
    cout << soln.rob(n1) << endl;
    return 0;
}

