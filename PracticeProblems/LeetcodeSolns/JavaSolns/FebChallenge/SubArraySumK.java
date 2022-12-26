// Leetcode #560 - Subarray sum equals K

import java.util.HashMap;

class SubArraySumK{
    // brute force - quadratic
    static int subArraySumI(int[] nums, int k){
        int count = 0, n = nums.length;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }

    // optimal - linear
    static int subArraySumII(int[] nums, int k){
        int count = 0, n = nums.length, sum = 0;
        HashMap<Integer, Integer> hmap = new HashMap<>();
        hmap.put(0, 1);
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int x = sum - k;
            // if cumulative sum already exists
            if(hmap.containsKey(x))
                // add number of its occurrences
                count += hmap.get(x);
            hmap.put(sum, hmap.getOrDefault(sum, 0) + 1);
        }
        return count;
    }

    public static void main(String[] args){
        int[] arr1 = {1, 1, 1};
        int[] arr2 = {1, 2, 3};
        int[] arr3 = {1, -1, 0};
        int[] arr4 = {3, 4, 7, 2, -3, 1, 4, 2};
        System.out.println(subArraySumII(arr1, 2)); // 2
        System.out.println(subArraySumII(arr2, 3)); // 2
        System.out.println(subArraySumII(arr3, 0)); // 3
        System.out.println(subArraySumII(arr4, 7)); // 4
    }
}
