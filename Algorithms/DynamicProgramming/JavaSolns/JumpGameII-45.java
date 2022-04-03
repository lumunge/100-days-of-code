// Leetcode #45 - Jump game II

class JumpGame{
    static int jumps(int[] nums){
        int far = 0, furthest = 0, count = 0;
        int n = nums.length;

        for(int i = 0; i < n-1; i++){
            far = Math.max(far, nums[i] + i);
            if(furthest == i){
                // shift pointers
                furthest = far;
                far = 0;
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args){
        int[] n = {2,3,1,1,4};
        int[] n1 = {2,3,0,1,4};
        System.out.println(jumps(n));
        System.out.println(jumps(n1));
    }
}
