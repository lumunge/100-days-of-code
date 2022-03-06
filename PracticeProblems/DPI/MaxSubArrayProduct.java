// Leetcode #1567 - Maximum length of subarray with positive product

class MaxSubArrayProduct{
    static int maxLen(int[] nums){
        int n = nums.length;
        int maxLen = 0, neg = 0;
        int negIdx = -1, zeroIdx = -1;

        for(int i = 0; i < n; i++){
            if(nums[i] < 0){ // set boolean
                neg++;
                if(negIdx == -1) negIdx = i;
            }
            if(nums[i] == 0){
                // reset everything start counting length
                zeroIdx = i;
                neg = 0;
                negIdx = -1;

            }else{
                // evaluate length
                if(neg%2 == 0) maxLen = Math.max(i - zeroIdx, maxLen);
                // odd negatives, remove the first negative
                else maxLen = Math.max(i - negIdx, maxLen);
            }
        }

        return maxLen;
    }

    public static void main(String[] args){
        int[] nums = {1, -2, -3, 4}; // 4
        int[] nums1 = {0, 1, -2, -3, -4}; // 3
        int[] nums2 = {-1, -2, -3, 0, 1}; // 2
        System.out.println(maxLen(nums));
        System.out.println(maxLen(nums1));
        System.out.println(maxLen(nums2));
    }
}
