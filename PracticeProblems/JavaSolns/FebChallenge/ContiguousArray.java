// Leetcode 525 -  contiguous array

import java.util.Map;
import java.util.HashMap;

class ContiguousArray{
    // brute force - quadractic
    static int findMaxLenI(int[] nums){
        int maxLen = 0;
        for(int i = 0; i < nums.length; i++){
            int ones = 0, zeros = 0;
            for(int j = i; j < nums.length; j++){
                if(nums[j] == 0) zeros++;
                else ones++;
                if(zeros == ones)
                    maxLen = Math.max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // optimal - linear
    static int findMaxLenII(int[] nums){
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int maxLen = 0, count = 0;
        for(int i = 0; i < nums.length; i++){
            count += (nums[i] == 1 ? 1 : -1);
            if(map.containsKey(count)) maxLen = Math.max(maxLen, i - map.get(count));
            else map.put(count, i);
        }
        return maxLen;
    }

    public static void main(String[] args){
        int arr[] = {0, 1};
        int arr1[] = {0, 1, 0};
        System.out.println(findMaxLenII(arr));
        System.out.println(findMaxLenII(arr1));
    }
}
