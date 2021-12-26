/* 
 * PROBLEM STATEMENT:
 * Given an array of points points[i] = [xi, yi], return the k closest points to the origin
 * (0, 0).
 * Distance between two points on the X-Y plane is the Euclidean distance;
 * Sqrt((x1 - x2)^2 + (y1 - y2)^2)
 *
 * Sample:
 * Input: points = [[1,3],[-2,2]], k = 1
 * Output: [[-2,2]]
 * Explanation:
 * sqrt(8) < sqrt(10) therfore return [[-2, 2]]
 *
 * Input: points = [[3,3],[5,-1],[-2,4]], k = 2
 * Output: [[3,3],[-2,4]]
 * Explanation:
 * sqrt(18) && sqrt(20) < sqrt(26), we get two because k = 2
 *
 * Approach:(sort with comparator) O(N * logN) and O(N) space
 * Sort the array with a using the euclidean distance and return the first k elements.
 *  
 * Approach 2: Quick Select Algorithm.
 */

import java.util.Arrays;

class KClosestPoint{
    private static int eDist(int point[]){
        int x = point[0] * point[0];
        int y = point[1] * point[1];
        return x + y;
    }

    public static int[][] closest(int[][] points, int k){
        Arrays.sort(points, (x, y) -> eDist(x) - eDist(y));
        return Arrays.copyOf(points, k);
    }
    
    public static void printArr(int[][] arr){
        for(int i = 0; i < arr.length; i++)
            System.out.println(arr[i][0] + " " + arr[i][1]);
    }

    public static void main(String args[]){
        int points[][] = {{3,3},{5,-1},{-2,4}};
        int k = 2;
        int points1[][] = {{1,3},{-2,2}};
        int k1 = 1;
        printArr(closest(points, k));
        System.out.println();
        printArr(closest(points1, k1));
    }
}
