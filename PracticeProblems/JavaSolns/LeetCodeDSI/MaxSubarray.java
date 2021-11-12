// Leetcode 53
//
class MaxSubarray{
    public static int maxSubArray(int[] nums){
        int posSegment = 0, posSegmentSum = Integer.MIN_VALUE;
        for(int i = 0; i < nums.length; i++){
            posSegment += nums[i];
            if(posSegmentSum < posSegment)
                posSegmentSum = posSegment;
            if(posSegment < 0)
                posSegment = 0;
        }
        return posSegmentSum;
    }

    public static void main(String args[]){
        int[] nums = {-1, -1, -3, 4, -1, 2, 1, -5, 4};
        int result = maxSubArray(nums);
        System.out.println(result);
    }
}
