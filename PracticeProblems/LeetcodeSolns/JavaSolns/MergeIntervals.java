/* 
 * PROBLEM STATEMENT:
 * Given an array of intervals where intervals[i] = [start(i) end(i)]
 * Merge overlapping intervals and return an array of non-overlapping 
 * intervals covering all input intervals.
 *
 * Sample:
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 *
 * Explanation: The resulting intervals cover all intervals in input array
 *               overlapping interval [1, 3], [2, 6] = [1, 6]
 * 
 * Approach.
 * Sort the array of arrays.
 * Traverse checking conditions for merging, that is, if
 * the end interval of the next array is less than or equal to the 
 * start interval of the preceding array, merge the two by replacing the 
 * ending interval of the preceding array with the end interval of the
 * next array, otherwise add an array to the resulting array.
 * We store currentInterval array for comparisons
 */

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

class MergeIntervals{ 
    public static int[][] merge(int[][] intervals){
        //check error input
        if(intervals.length <= 1) return intervals;
        //sort array and internal arrays
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> result = new ArrayList<>();
        //add first array to result array
        int[] currInterval = intervals[0];
        result.add(currInterval);
        //traverse intervals
        for(int[] interval : intervals){
            if(currInterval[1] >= interval[0]){
                currInterval[1] = Math.max(currInterval[1], interval[1]);
            }else{
                currInterval = interval;
                result.add(currInterval);
            }
        }
        //convert list to 2d array
        return result.toArray(new int[result.size()][]);
    }
    //print array
    public static void printArr(int[][] arr){
        for(int i = 0; i < arr.length; i++)
            System.out.println(arr[i][0] + " " + arr[i][1]);
        System.out.println();
    }
    public static void main(String[] args){
        int[][] intervals = {{1,3},{2,6},{8,10},{15,18}};
        int [][] intervals1 = {{1, 4}, {4, 5}};
        printArr(merge(intervals));
        printArr(merge(intervals1));
    }
    
}
