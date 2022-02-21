// Leetcode #169 - Majority element

import java.util.HashMap;
import java.util.Arrays;

class MajorityElement{
    static int majority(int[] nums){
        HashMap<Integer, Integer> map = new HashMap();
        int n = nums.length;
        int m = n / 2;
        int res = 0;
        
        for(int i = 0; i < n; i++)
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        
        for(Map.Entry<Integer, Integer> entry : map.entrySet()){
            if(entry.getValue() > m)
                res = entry.getKey();
        }
        return res;
    }
    static int majorityI(int[] nums){
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
}
