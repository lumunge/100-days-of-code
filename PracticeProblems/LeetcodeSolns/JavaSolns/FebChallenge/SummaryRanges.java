// Leetcode #228 - Summary Ranges

import java.util.List;
import java.util.ArrayList;

class SummaryRanges{
    static List<String> ranges(int[] nums){
        List<String> res = new ArrayList();
        
        int n = nums.length;
        for(int i = 0; i < nums.length; i++){
            int start = nums[i];
            
            while(i+1 < nums.length && nums[i] == nums[i+1] - 1)
                i++;
            
            if(start != nums[i])
                res.add(""+start+"->"+nums[i]);
            else
                res.add(""+start);
        }
        return res;
    }
    public static void main(String[] args){
        int[] nums = {0,1,2,4,5,7};
        int[] nums1 = {0,2,3,4,6,8,9};
        List<String> res = ranges(nums);
        List<String> res1 = ranges(nums1);
        System.out.println(res);
        System.out.println(res1);
    }
}
