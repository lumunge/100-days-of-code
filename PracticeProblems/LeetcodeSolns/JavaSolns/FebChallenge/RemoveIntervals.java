// Leetcode #1288 - Remove covered intervals

import java.util.Arrays;

class RemoveIntervals{
    static int removeIntervals(int[][] intervals){
        Arrays.sort(intervals, (a, b) -> (a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]));
        int count = 0;
        int curr = 0;
        for(int i[] : intervals){
            if(curr < i[1]){
                curr = i[1];
                count++;
            } 
        }
        return count;
    }
    public static void main(String[] args){
        int[][] intervals = {{1, 4}, {3, 6}, {2, 8}};
        int[][] intervals1 = {{1, 4}, {2, 3}};
        System.out.println(removeIntervals(intervals));
        System.out.println(removeIntervals(intervals1));
    }
}
