// Leetcode #213 - House Robber II

#include<iostream>
#include<vector>
#include<algorithm>

using std::max;
using std::vector;
using std::cout;
using std::endl;

class HouseRobberII{
    private:
        int hr1(vector<int>& nums){
            int max1 = 0, max2 = 0;
            for(int n : nums){
                int temp = max(n + max1, max2);
                max1 = max2;
                max2 = temp;
            }
            return max2;
        }
    public:
        int robber(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
            vector<int> nums1, nums2;
            for(int i = 1; i < n; i++) nums1.push_back(nums[i]);
            for(int i = 0; i < n-1; i++) nums2.push_back(nums[i]);
            return max(hr1(nums1), hr1(nums2));
        }
};

int main(){
    HouseRobberII soln;
    vector<int> nums = {2, 3, 2}; // 3
    vector<int> nums1 = {1, 2, 3, 1}; // 4
    vector<int> nums2 = {1, 2, 3}; // 3
    vector<int> nums3 = {200, 3, 140, 20, 10}; // 340
    cout << soln.robber(nums) << endl; 
    cout << soln.robber(nums1) << endl; 
    cout << soln.robber(nums2) << endl; 
    cout << soln.robber(nums3) << endl; 
    return 0;
}
