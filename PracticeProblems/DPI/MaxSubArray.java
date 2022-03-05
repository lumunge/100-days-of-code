// Leecode #53 - Maximum subarray

class MaxSubArray{
	static int maxSubArray(int[] nums){
	    int max1 = 0, max2 = Integer.MIN_VALUE;
            for(int i = 0; i < nums.length; i++){
		        max1 += nums[i];
                if(max1 > max2) max2 = max1;
                if(max1 < 0) max1 = 0;
            }
            return max2;
    	}
        public static void main(String[] args){
            int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
            int[] nums1 = {-1};
                int[] nums2 = {5,4,-1,7,8};
            System.out.println(maxSubArray(nums));
            System.out.println(maxSubArray(nums1));
            System.out.println(maxSubArray(nums2));
        }
}
