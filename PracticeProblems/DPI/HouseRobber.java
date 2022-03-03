// Leetcode #198 - House Robber I

class HouseRobberI{
    static int robber(int[] nums){
        int max1 = 0, max2 = 0;
        
        for(int n : nums){
            int temp = Math.max(n + max1, max2);
            max1 = max2;
            max2 = temp;
        }
        return max2;
    }
    public static void main(String[] args){
        int[] nums = {1, 2, 3, 1};
        int[] nums1 = {2, 7, 9, 3, 1};
        System.out.println(robber(nums));
        System.out.println(robber(nums1));
    }
}
