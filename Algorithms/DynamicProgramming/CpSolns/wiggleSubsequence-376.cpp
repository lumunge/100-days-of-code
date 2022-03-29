// Leetcode #376 - Wiggle subsequence

#include<vector>
#include<iostream>

using std::vector; using std::max;
using std::cout; using std::endl;

class Solution{
    public:
        int maxWiggle(vector<int>& nums){
            int n = nums.size();
            if(n < 2) return n;
            int up = 1, down = 1;
            for(int i = 1; i < n; i++){
                // wiggles up
                if(nums[i] > nums[i - 1])
                    up = down + 1;
                // wiggles down
                else if(nums[i] < nums[i - 1])
                    down = up + 1;
            }
            return max(up, down);
        }
};

int main(){
    Solution soln;
    vector<int> n = {1,7,4,9,2,5};
    vector<int> n1 = {1,17,5,10,13,15,10,5,16,8};
    vector<int> n2 = {1,2,3,4,5,6,7,8,9};
    cout << soln.maxWiggle(n) << endl;
    cout << soln.maxWiggle(n1) << endl;
    cout << soln.maxWiggle(n2) << endl;
    return 0;
}
