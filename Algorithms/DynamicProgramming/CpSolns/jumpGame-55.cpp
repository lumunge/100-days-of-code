// Leetcode #55 - Jump game

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

class Solution{
    public:
        bool canJump(vector<int>& nums){
            int n = nums.size(), reach = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] + i > reach) reach = nums[i] + i;
                if(reach == i) break;
            }
            return reach >= n-1;
        }
};

int main(){
    Solution soln;
    vector<int> n = {2,3,1,1,4};
    vector<int> n1 = {3,2,1,0,4};
    cout << soln.canJump(n) << endl;
    cout << soln.canJump(n1) << endl;
    return 0;
}
