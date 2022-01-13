/* PROBLEM STATEMENT:
 * Given spherical ballons on an XY plane, you can shoot arrows upwards.
 * Given an array of points representing ballons, return the minimum number of arrows
 * that can be shot.
 *
 * Approach;
 * Intervals problem.
 */

import java.util.Arrays;

class MinArrows{
    static int minArrows(int[][] points){
        if(points.length <= 1) return 1;
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
        int count = 1;
        int curr = points[0][1];
        for(int[] p : points){
            if(p[0] > curr){
                curr = p[1];
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args){
        int[][] points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
        int[][] points1 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
        System.out.println(minArrows(points));
        System.out.println(minArrows(points1));
    }
}
