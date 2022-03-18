// Leetcode #413 - Arithmetic slices

#include<iostream>
#include<vector>

using std::vector;
using std::cout; using std::endl;

class Solution{
    public:
        int slicesI(vector<int>& nums){
            int slices = 0, curr = 0;
            for(int i = 2; i < nums.size(); i++){
                if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                    curr++;
                    slices += curr;
                }else{
                    curr = 0;
                }
            }
            return slices;
        }
};

int main(){
    Solution soln;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> nums1 = {1};
    vector<int> nums2 = {3, -1, -5, -9};
    cout << soln.slicesI(nums) << endl;
    cout << soln.slicesI(nums1) << endl;
    cout << soln.slicesI(nums2) << endl;
    return 0;
}
