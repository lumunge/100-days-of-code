#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using std::vector;
using std::set;
using std::cout;
using std::endl;

class Solution{
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
            vector<int> result;
            vector<int> finalRes;
            for(int i = 0; i < nums1.size(); i++){
                result.push_back(nums1[i]);
            }
            for(int i = 0; i < nums2.size(); i++){
                if(find(result.begin(), result.end(), nums2[i]) != result.end())
                    finalRes.push_back(nums2[i]);
            }
            return finalRes;
        }
};

int main(){
    Solution soln;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> result = soln.intersect(nums1, nums2);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
