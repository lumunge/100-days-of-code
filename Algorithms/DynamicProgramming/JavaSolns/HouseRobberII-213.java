// Leetcode #213 - House robber II

import java.util.ArrayList;
import java.util.List;

class HouseRobber{
    private static int hr1(List<Integer> nums){
        int max1 = 0, max2 = 0;
        for(int n : nums){
            int temp = Math.max(max1 + n, max2);
            max1 = max2;
            max2 = temp;
        }
        return max2;
    } 
    public static int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        List<Integer> l1 = new ArrayList<>();
        List<Integer> l2 = new ArrayList<>();
        for(int i = 0; i < n-1; i++) l1.add(nums[i]);
        for(int i = 1; i < n; i++) l2.add(nums[i]);
        return Math.max(hr1(l1), hr1(l2));
    }
    public static void main(String[] args){
        int[] n = {2, 3, 2};
        int[] n1  ={1, 2, 3, 1};
        int[] n2 = {1, 2, 3};
        System.out.println(rob(n));
        System.out.println(rob(n1));
        System.out.println(rob(n2));
    }
}
