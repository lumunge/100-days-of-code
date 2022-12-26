/* 
 * PROBLEM STATEMENT:
 * Given an array of distinct integers, return all pairs with the minimum absolute difference
 * of any two elements.
 *
 * Sample:
 * Input: arr = [4,2,1,3]
 * Output: [[1,2],[2,3],[3,4]]
 *
 * Explanation: All have the minimum absolute difference of 1.
 *
 * Approach:
 * Sort the input array
 * Initialize difference to the largest MAX_VALUE
 * Traverse the array
 * If a difference between two elements is less than min difference
 * add the two elements to a list and add the list to resulting list.
 * return resulting list.
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

class MinAbsDiff{
    static List<List<Integer>> minimumAbsDifference(int[] arr){
        List<List<Integer>> res = new ArrayList<>();
        int minDiff = Integer.MAX_VALUE;
        Arrays.sort(arr);

        for(int i = 0; i < arr.length-1; i++){
            int diff = arr[i+1] - arr[i];
            if(diff == minDiff)
                res.add(Arrays.asList(arr[i], arr[i+1]));
            else if(diff < minDiff){
                res.clear();
                res.add(Arrays.asList(arr[i], arr[i+1]));
                minDiff = diff;
            }
        }
        return res;
    }
    public static void main(String[] args){
        int arr[] = {4, 2, 1, 3};
        List<List<Integer>> res = minimumAbsDifference(arr);
        for(int i = 0; i < res.size(); i++)
            for(int j = 0; j < res.get(i).size(); j++)
                System.out.println(res.get(i).get(j));
    }
}
