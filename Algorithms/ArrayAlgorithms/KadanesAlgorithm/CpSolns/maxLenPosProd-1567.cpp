// Leetcode #1567 - Maximum length of subarray with positive product

#include<iostream>
#include<vector>

using std::max; using std::vector;
using std::cout; using std::endl;

class Solution{
    public:
        int maxLen(vector<int>& nums){
            int n = nums.size();
            int maxLen = 0, neg = 0;
            int negIdx = -1, zeroIdx = -1;

            for(int i = 0; i < n; i++){
                // negative
                if(nums[i] < 0){
                    neg++;
                    if(negIdx == -1) negIdx = i;
                }
                // zero
                if(nums[i] == 0){
                    zeroIdx = i;
                    // reset negs
                    neg = 0; negIdx = -1;
                }else{// positive
                    if(neg % 2 == 0)
                        maxLen = max(maxLen, i - zeroIdx);
                    else
                        maxLen = max(maxLen, i - negIdx);
                }
            }

            return maxLen;
        }
};

int main(){
    Solution soln;
    vector<int> n = {1, -2, -3, 4};
    vector<int> n1 = {0, 1, -2, -3, -4};
    vector<int> n2 = {-1, -2, -3, 0, 1};
    cout << soln.maxLen(n) << endl;
    cout << soln.maxLen(n1) << endl;
    cout << soln.maxLen(n2) << endl;
    return 0;
}
