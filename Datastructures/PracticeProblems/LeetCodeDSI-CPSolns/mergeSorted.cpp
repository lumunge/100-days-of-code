#include<bits/stdc++.h>

/* PROBLEM STATEMENT:
 * Given two sorted arrays and two integers. Merge array 2 into array 1 which is sorted in
 * non-decreasing order, array 2 has a length of sum of m + n.
 *
 * Input: nums1 = [1, 2, 3, 0, 0, 0]
 *        nums2 = [2, 5, 6]
 *        m = 3
 *        n = 3
 * Output: nums1 = [1, 2, 2, 3, 5, 6]
 *
 * Approach:
 * 1. Initialize pointers pointing to last elements of each array, i pointing to last
 *    position of first array with valid values, j to last position of second array,
 *    k to last position of whole array both valid and invalid.
 * 2. Loop comparing elements, if last valid element in first array is greater than last
 *    last valid element in second array, append it to last position of first array
 *    otherwise append element in array 2 to the last position of array 1.
 * 3. Get remaining elements from array 2 and push them to front of array 1.
 */

class Solution{
    public:
        void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n){
            int i = m-1;
            int j = n-1;
            //pointer to last index of nums1
            int k = (m + n) - 1;
            
            //merge elements to nums1 in reverse order
            while(i >= 0 && j >= 0){
                if(nums1[i] >= nums2[j]){
                    nums1[k--] = nums1[i--];
                }else{
                    nums1[k--] = nums2[j--];
                }
            }

            //Move remaining elements to nums1 from nums2
            while(j >= 0){
                nums1[k--] = nums2[j--];
            }
        }
};

int main(){
    Solution soln;
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    int n1 = 3;
    int n2 = 3;
    soln.merge(nums1, n1, nums2, n2);
    for(int i = 0; i < nums1.size(); i++){
        std::cout << nums1[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
