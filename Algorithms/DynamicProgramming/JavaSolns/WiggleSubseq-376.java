// Leetcode #376 - Wiggle subsequence

class WiggleSubseq {
    public int wiggleMaxLength(int[] nums) {
        int n = nums.length;
        if(n < 2) return n;
        int up = 1, down = 1;
        for(int i = 1; i < n; i++){
            // it wiggles up
            if(nums[i] > nums[i-1])
                up = down + 1;
            // it wiggles down
            else if(nums[i] < nums[i - 1])
                down = up + 1;
        }
        return Math.max(up, down);
    }
}
