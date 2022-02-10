// Leetcode #560 - Subarray sum equals K

class SubArraySumK{
    // brute force
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

    public static void main(String[] args){
        int[] arr1 = {1, 1, 1};
        int[] arr2 = {1, 2, 3};
        int[] arr3 = {1, -1, 0};
        int[] arr4 = {3, 4, 7, 2, -3, 1, 4, 2};
        System.out.println(subArraySumI(arr1, 2)); // 2
        System.out.println(subArraySumI(arr2, 3)); // 2
        System.out.println(subArraySumI(arr3, 0)); // 3
        System.out.println(subArraySumI(arr4, 7)); // 4
    }
}
