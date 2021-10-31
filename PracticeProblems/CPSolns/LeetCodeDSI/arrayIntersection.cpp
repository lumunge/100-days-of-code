#include<bits/stdc++.h>

class Solution{
    public:
        void intersect(std::vector<int>& nums1, std::vector<int>& nums2){
            for(int i = 0; i < nums1.size(); i++){
                for(int j = i+1; j < nums2.size(); j++){
                    std::cout << nums1[i] << " " << nums2[j] << std::endl;
                }
            }
        }
};

int main(){
    Solution soln;
    std::vector<int> nums1 = {4, 9, 5};
    std::vector<int> nums2 = {9, 4, 9, 8, 4};
    soln.intersect(nums1, nums2);
    return 0;
}
