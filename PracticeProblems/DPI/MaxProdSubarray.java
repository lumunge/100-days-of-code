// Leetcode 

class MaxProdSubarray{
    static int maxProd(int[] nums){
        int max1 = 1, max2 = 1, res = 0;
        for(int i = 0; i < nums.length; i++){
            int temp = Math.max(nums[i], Math.max(nums[i] * max1, nums[i] * max2));
            max2 = Math.min(nums[i], Math.min(nums[i] * max1, nums[i] * max2));
            max1 = temp;
            res = Math.max(max1, res);
        }
        return res;
    }
    public static void main(String[] args){
        int[] nums = {2, 3, -2, 4};
        System.out.println(maxProd(nums));
    }
}
