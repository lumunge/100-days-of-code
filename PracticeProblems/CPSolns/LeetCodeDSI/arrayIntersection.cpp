#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using std::unordered_map;
using std::vector;
using std::cout;
using std::endl;

/* PROBLEM STATEMENT:
 * Given two integer arrays nums1, nums2, return an array of their intersection, each element in the
 * resulting array must appear as many times in both arrays.
 *
 * Sample:
 * Input: nums1 = [1, 2, 2, 1]
 *        nums2 = [2, 2]
 * Output: [2, 2]
 *
 * Input: nums1 = [4, 9, 3, 6, 7]
 *        nums2 = [ 11, 6, 3, 1, 2]
 * Output: [6, 3]
 *
 * Approach 1: 
 * Sort both arrays
 * Use loops to compare elements in each, if nums1 element is less than nums2 element, increment
 * nums1 index, if less increment nums2 index, otherwise they are equal, place one of the element at 
 * the front of nums1.
 * Return the first portion of nums1 array which will have intersecting elements.
 *
 * Approach 2:
 * Find a larger size array between the two and swap to get smaller array.
 * Insert elements of smaller array to a hash map with their counts.
 * Loop through elements of the second array,
 * If the count is greater than 0, place the element in first position of nums1, and decrement its
 * count.
 * Finally return the first portion of elements in nums1
 */

class Solution{
    public:
        //approach 1 using loop
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
        
        //approach 2 using hashmap
        vector<int> intersectII(vector<int>& nums1, vector<int>& nums2){
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
                    nums1[k] = i;
                    k++;
                    --umap[i];
                }
            }
            return vector<int>(nums1.begin(), nums1.begin() + k);
        }
        
        //print array
        void printArr(vector<int> arr){
            for(int i = 0; i < arr.size(); i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Solution soln;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> result2 = soln.intersectII(nums1, nums2);
    soln.printArr(result2);
    return 0;
}
