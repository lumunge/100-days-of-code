#include<bits/stdc++.h>

class Solution{
    public:
        void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n){
            int i = 0, j = 0, k = 0;

            while(i < m && j < n){
                if(nums1[i] < nums2[j]){
                    nums1[k] = nums1[i];
                    i++;
                }else{
                    nums1[k] = nums2[j];
                    k++;
                    j++;
                }
            }
            while(i < m){
                nums1[k++] = nums1[i++];
            }
            while(j < n){
                nums1[k++] = nums2[j++];
            }
        }
};

int main(){
    Solution soln;
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = 3;
    soln.merge(nums1, m, nums2, n);
    for(int i = 0; i < m+n; i++)
        std::cout << nums1[i] << std::endl;
    return 0;
}
