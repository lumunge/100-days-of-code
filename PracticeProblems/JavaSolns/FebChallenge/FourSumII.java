// Leetcode 454

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

    public static void main(String[] args){
        int[] nums1 = {1, 2}, nums2 = {-2, -1}, nums3 = {-1, 2}, nums4 = {0, 2};
        System.out.println(fourSum(nums1, nums2, nums3, nums4));
    }
}
