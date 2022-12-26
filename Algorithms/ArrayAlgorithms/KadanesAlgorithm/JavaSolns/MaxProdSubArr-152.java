// Leetcode #152 - Maximum product subarray

class MaxProdSubArr{
    static int maxProd(int[] nums){
        if(nums.length == 1) return nums[0];
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
        int[] n = {2, 3, -2, 4};
        int[] n1  ={-2, 0, -1};
        System.out.println(maxProd(n));
        System.out.println(maxProd(n1));
    }
}
