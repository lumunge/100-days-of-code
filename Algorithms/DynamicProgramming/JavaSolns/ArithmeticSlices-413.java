// Leetcode #413 - Arithmetic slices

class ArithmeticSlices{
    public int numberOfArithmeticSlices(int[] nums) {
        int slices = 0, curr = 0;
        for(int i = 2; i < nums.length; i++){
            // evaluate
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                curr++;
                slices += curr;
            }else{
                // reset
                curr = 0;
            }
        }
        return slices;
    }
}
