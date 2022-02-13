// Leetcode #78 - Subsets.

import java.util.ArrayList;
import java.util.List;

class Subsets{
    // generate new subset from each integer during traversal
    static List<List<Integer>> subsetsI(int[] nums){
        List<List<Integer>> res = new ArrayList<>();
        res.add(new ArrayList<Integer>());

        for(int n : nums){
            List<List<Integer>> subset = new ArrayList<>();
            for(List<Integer> curr : res)
                subset.add(new ArrayList<Integer> (curr){{add(n);}});
            for(List<Integer> curr : subset)
                res.add(curr);
        }
        return res;
    }

    public static void main(String[] args){
        int[] nums = {1, 2, 3};
        System.out.println(subsetsI(nums));
    }
}
