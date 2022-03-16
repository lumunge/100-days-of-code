// Leetcode #120 - Triangle

import java.util.List;

class Triangle{
    static int minTotal(List<List<Integer>> triangle){
        int n = triangle.size();
        int[] dp = new int[n];
        
        // bottom up
        for(int i = n - 1; i >= 0; i--){
            List<Integer> curr = triangle.get(i);
            dp[0] += curr.get(0);
            for(int j = 1; j < curr.size(); j++){
                dp[j] += curr.get(j);
                // adjacent and immediate
                dp[j - 1] = Math.min(dp[j], dp[j - 1]);
            }
        }
        return dp[0];
    }
}
