// Leetcode #80 - Remove duplicates from sorted array II

class RemoveDupilcatesArrayII.java{
    static int removeDuplicates(int[] nums){
        int n = nums.length;
        if(n < 3) return n;
        int s = 2, f = 2;
        for(int i = 2; i < nums.length; i++){
            if(nums[f] != nums[s-2])
                nums[s++] = nums[f];
            f++;
        }
        return s;
    }
}
