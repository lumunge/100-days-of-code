// Leetcode 525 -  contiguous array

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

    public static void main(String[] args){
        int arr[] = {0, 1};
        int arr1[] = {0, 1, 0};
        System.out.println(findMaxLenI(arr));
        System.out.println(findMaxLenI(arr1));
    }
}
