#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using std::unordered_map;
using std::vector;
using std::cout;
using std::endl;

class Solution{
    public:
        vector<int> intersectI(vector<int>& nums1, vector<int>& nums2){
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());

            int i = 0, j = 0, k = 0;

            while(i < nums1.size() && j < nums2.size()){
                if(nums1[i] < nums2[j])
                    i++;
                else if(nums1[i] > nums2[j])
                    j++;
                else{
                    nums1[k++] = nums1[i];
                    i++;
                    j++;
                }
            }
            return vector<int>(nums1.begin(), nums1.begin() + k);
        }

        vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
            int m = nums1.size();
            int n = nums2.size();
            unordered_map<int, int> umap;

            if(m > n)
                swap(nums1, nums2);
            
            for(auto i:nums1){
                umap[i]++;
            }

            int k = 0;
            for(auto i:nums2){
                if(umap[i] > 0){
                    nums1[k++] = i;
                    --umap[i];
                }
            }
            return vector<int>(nums1.begin(), nums1.begin() + k);
        }
            
};

int main(){
    Solution soln;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> result = soln.intersectI(nums1, nums2);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
