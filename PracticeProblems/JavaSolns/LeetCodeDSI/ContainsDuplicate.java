import java.util.*;

//Leetcode 217

public class ContainsDuplicate{
    static boolean containsDup(int[] nums){
        HashSet<Integer> hs = new HashSet<Integer>();
        boolean duplicate = false;
        for(int i = 0; i < nums.length; i++){
            if(hs.contains(nums[i]))
                duplicate = true;
            else
                hs.add(nums[i]);
        }
        return duplicate;
    } 

    public static void main(String[] args){
        int[] nums = {1, 2, 3};
        System.out.println(containsDup(nums));
    }
}
