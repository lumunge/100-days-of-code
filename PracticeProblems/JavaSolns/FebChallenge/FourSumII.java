// Leetcode 454

import java.util.Map;
import java.util.HashMap;

class FourSumII{
    // brute force
    static int fourSum(int[] nums1, int[] nums2, int[] nums3, int[] nums4){
        int tuples = 0;
        
        for(int n1 : nums1)
            for(int n2 : nums2)
                for(int n3 : nums3)
                    for(int n4 : nums4)
                        if(n1 + n2 + n3 + n4 == 0) tuples++;
        return tuples;
    }

    // optimized
    static int fourSumOpt(int[] nums1, int[] nums2, int[] nums3, int[] nums4){
        int tuples = 0;
        Map<Integer, Integer> map = new HashMap();
        for(int n1 : nums1)
            for(int n2 : nums2)
                map.put(n1 + n2, map.getOrDefault(n1 + n2, 0) + 1);
        for(int n3 : nums3)
            for(int n4 : nums4)
                tuples += map.getOrDefault(-(n3 + n4), 0);
        return tuples;
    }

    public static void main(String[] args){
        int[] nums1 = {1, 2}, nums2 = {-2, -1}, nums3 = {-1, 2}, nums4 = {0, 2};
        System.out.println(fourSumOpt(nums1, nums2, nums3, nums4));
    }
}
