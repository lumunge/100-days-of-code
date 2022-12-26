#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
    public:
        vector<int> runningSum(vector<int>& nums){
            int n = nums.size();
            for(int i = 1; i < n; i++){
                nums[i] += nums[i-1];
            }
            return nums;
        }
        void printVec(vector<int> v){
            int n = v.size();
            for(int i = 0; i < n; i++)
                cout << v[i] << " ";
            cout << endl;
        }
};

int main(){
    Solution soln;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = soln.runningSum(nums);
    soln.printVec(res);
    return 0;
}
