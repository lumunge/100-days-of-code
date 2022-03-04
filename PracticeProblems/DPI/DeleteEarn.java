// Leetcode #740 - Delete and earn.

import java.util.HashMap;

class DeleteEarn{
    static int delEarn(int[] nums){
        int point = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        
        // add nums:totalPoints to hashmap
        for(int n : nums){
            map.put(n, map.getOrDefault(n, 0) + n);
            point = Math.max(point, n);
        }
        
        // result array
        int[] arr = new int[point + 1];
        arr[1] = map.getOrDefault(1, 0);
        
        for(int i = 2; i < arr.length; i++){
            int prev = map.getOrDefault(i, 0);
            arr[i] = Math.max(arr[i-1], arr[i-2] + prev);
        }
        // bottom-up dp, return last element of array
        return arr[arr.length - 1];
    }
    public static void main(String[] args){
        int[] nums = {4};
        int[] nums1 = {3, 4, 2};
        int[] nums2 = {2, 2, 3, 3, 3, 4};
        int[] nums3 = {1, 1, 1, 2, 4, 5, 5, 5, 6};
        System.out.println(delEarn(nums));
        System.out.println(delEarn(nums1));
        System.out.println(delEarn(nums2));
        System.out.println(delEarn(nums3));
    }
}
