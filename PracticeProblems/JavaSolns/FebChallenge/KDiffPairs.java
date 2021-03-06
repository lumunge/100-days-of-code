// Leetcode #532 - k-diff pairs in an array

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.Map;
import java.util.HashMap;

class KDiffPairs{
    // using hashset
    static int findPairsI(int[] nums, int k){
        // sort array
        Arrays.sort(nums);
        int n = nums.length;
        Set<Integer> hset = new HashSet<>();

        for(int i = 0; i < n-1; i++){
            // search for i + k from (i+1 - n)
            if(Arrays.binarySearch(nums, i+1, n, nums[i] + k) > 0)
                // add to set to avoid duplicates
                hset.add(nums[i]);
        }
        return hset.size();
    }

    // using hashmap
    static int findPairsII(int[] nums, int k){
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;
        
        // add to map
        for(int i : nums){
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        
        // traverse map
        for(int i : map.keySet()){
            // if k > 0 - check for i + k existence
            // if k == 0 - check count of i in map
            if(k > 0 && map.containsKey(i + k) || k == 0 && map.get(i) > 1)
                count++;
        }
        
        return count;
    }

    public static void main(String[] args){
        int[] nums1 = {3, 1, 4, 1, 5};
        int[] nums2 = {1, 2, 3, 4, 5};
        System.out.println(findPairsII(nums1, 2));
        System.out.println(findPairsII(nums1, 0));
        System.out.println(findPairsII(nums2, 1));
        System.out.println(findPairsII(nums2, 0));
    }
}
