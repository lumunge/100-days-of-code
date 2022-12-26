/*
 * PROBLEM STATEMENT:
 * Given two sorted arrays nums2 and nums2 of size m and n, return median of the two.
 * Time complexity should be O(log(m+n))
 * 
 * Sample:
 * Input: nums1 = [1, 3], num2 = [2];
 * Output: nums3 = [1, 2, 3], median = 2.00000
 *
 * Input: num1 = [1, 2], nums2 = [3, 4];
 * Ouput: nums3 = [1, 2, 3, 4], median = 3+2 = 5/2 = 2.50000
 *
 * Approach.
 * Median is the value separating the higher from the lower values.
 * Merge the two sorted arrays to attain a merged sorted array
 * If array length of new array is even,
 *      median is the sum of two middle elements divided by two
 * else
 *      median is middle element, newArray[length/2]
 * return median.
 */

class MedianArray{
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double median = 0;
        int n1 = nums1.length, n2 = nums2.length;
        int nums3[] = new int[n1+n2];
        int i = 0, j = 0, k = 0;
        //merge the two arrays to one sorted array
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j])
                nums3[k++] = nums1[i++];
            else
                nums3[k++] = nums2[j++];
        }
        while(i < n1)
            nums3[k++] = nums1[i++];
        
        while(j < n2)
            nums3[k++] = nums2[j++];
        //calculate the median 
        int n3 = nums3.length;
        if(n3 % 2 == 0){
            median = (float)(nums3[n3/2] + nums3[(n3/2)-1]) / 2;
        }else{
            median = (float)nums3[n3/2];
        }
        return median;
    }
};
