// Leetcode 1

import java.util.HashMap;
class TwoSum{
    public static int[] Solution(int[] nums, int target){
        HashMap<Integer, Integer> map = new HashMap<>();
        int res[] = new int[2];
        for(int i = 0; i < nums.length; i++){
            int diff = target - nums[i];
            if(map.containsKey(diff)){
                res[0] = i;
                res[1] = map.get(diff);
                break;
            }
            map.put(nums[i], i);
        }
        return res;
    }

    public static void main(String[] args){
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        int[] res = Solution(nums, target);
        for(int i = 0; i < res.length; i++){
            System.out.println(res[i]);
        }
    }
}
