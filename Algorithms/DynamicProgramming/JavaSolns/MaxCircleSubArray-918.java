// Leetcode #918

class MaxCircleSubArray{
    public static int maxSum(int[] nums){
        int maxSum = Integer.MIN_VALUE, minSum = Integer.MAX_VALUE;
        int maxEnding = 0, minEnding = 0, total = 0;
        
        for(int n : nums){
            total += n;
            maxEnding = Math.max(maxEnding + n, n);
            maxSum = Math.max(maxEnding, maxSum);
            minEnding = Math.min(minEnding + n, n);
            minSum = Math.min(minEnding, minSum);
        }
        return (maxSum > 0) ? Math.max(maxSum, total - minSum) : maxSum;
    }
    public static void main(String[] args){
        int[] n = {1,-2,3,-2};
        int[] n1 = {5,-3,5};
        int[] n2 = {-3,-2,-3};
        System.out.println(maxSum(n));
        System.out.println(maxSum(n1));
        System.out.println(maxSum(n2));
    }
}
