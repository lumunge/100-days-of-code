#include<bits/stdc++.h>


/* 
 * PROBLEM STATEMENT:
 * Given an integer array nums, return the largest sum of a contigous subarray.
 *
 * Sample:
 * Input: [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6 = [4, -1, 2, 1]
 *
 * Approach 1: Using Divide and Conquer. O(nlogn)
 * 1. Divide the array into 2 subarrays
 * 2. Get max subarray sum of left subarray recursively
 * 3. Get max subarray sum of right subarray recursively
 * 4. Get max subarray sum that crosses the mid element
 * 5. Return max(2, 3, 4) above
 *
 * Approach 2: Kadanes algorithm. O(n)
 * 1. Initialize two variables, one to keep track of positive contigous segments (posSegment), one to track their sum (posSegmentSum)
 * 2. Loop through array elements
 * 3. Add array elements to posSegment
 * 4. If posSegmentSum < posSegment, posSegmentSum = posSegment
 * 5. If posSegment < 0, posSegment = 0
 * 6. Return posSegmentSum
 */


class Solution{
    public:
        //Using Divide and Conquer
        int maxCrossingSum(std::vector<int>& nums){
            int l = 0;
            int r = nums.size();
            int m = (l + r) / 2;
            int sum = 0;
            int leftSum = INT_MIN;
            //elements to left of mid
            for(int i = m; i >= l; i--){
                sum += nums[i];
                if(sum > leftSum)
                    leftSum = sum;
            }

            //elements to right of mid
            sum = 0;
            int rightSum = 0;
            for(int i = m + 1; i <= r; i++){
                sum += nums[i];
                if(sum > rightSum)
                    rightSum = sum;
            }
            return std::max(std::max(leftSum + rightSum, leftSum), rightSum);
        }

        int maxSubArray(std::vector<int>& nums, int l, int r){
            if(l == r)
                return nums[l];
            int m = (l + r) / 2;
            return std::max(std::max(maxSubArray(nums, l, m), maxSubArray(nums, m+1, r)), maxCrossingSum(nums));
        }

        //Using kadane's algorithm
        int maxSubArrayII(std::vector<int>& nums){
            int posSegment = 0, posSegmentSum = 0;
            for(int i = 0; i < nums.size(); i++){
                posSegment += nums[i];
                if(posSegmentSum < posSegment)
                    posSegmentSum = posSegment;
                if(posSegment < 0)
                    posSegment = 0;
            }
            return posSegmentSum;
        }

};

int main(){
    Solution soln;
    std::vector<int> nums = {5,4,-1,7,8};
    std::cout << soln.maxSubArrayII(nums) << std::endl;
    return 0;
}
