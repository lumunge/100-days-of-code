#include<iostream>
#include<vector>
#include<limits.h>

using std::vector;
using std::cout;
using std::min;

class Solution{
    public:
        int minSubArray(vector<int>& nums, int s){
            int n = nums.size();
            if(n == 0) return 0;
            int res = INT_MAX;
            vector<int> sums(n+1, 0); // fill arr[n+1] with 0
            for(int i = 1; i <= n; i++)
                sums[i] = nums[i-1] + sums[i-1];
            for(int i = 1; i <= n; i++){
                int x = s + sums[i-1];
                auto b = lower_bound(sums.begin(), sums.end(), x);
                if(b != sums.end())
                    res = min(res, static_cast<int>(b - (sums.begin() + i - 1)));
            }
            return (res != INT_MAX) ? res : 0;
        }
};

int main(){
    Solution soln;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int s = 7;
    cout << soln.minSubArray(nums, s) << "\n";
    return 0;
}
