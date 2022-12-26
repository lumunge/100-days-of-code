// Leetcode #136 - find a number in array that appears once.

import java.util.Arrays;

class SingleNumber{
    static int singleNumber{
        Arrays.sort(nums);
        int n = nums.length;
        for(int i = 0; i < n-1; i+=2){
            if(nums[i] != nums[i + 1])
                return nums[i];
        }
        return nums[n-1];
    }
}
