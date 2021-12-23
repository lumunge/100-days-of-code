/* 
 * PROBLEM STATEMENT
 * Given numCourses courses, take courses labelled from 0 - numCourses-1.
 * You are also given prerequisites where prerequisites[i] = [ai, bi] indicating that bi is
 * a prerequisites for ai.
 * Return the ordering of courses to take to finish all courses otherwise return an empty
 * array.
 *
 * Sample.
 * Input: numCourses = 4
 *        prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0, 2, 1, 3] / [0, 1, 2, 3]
 * Explanation: Do course 0 then 1 or 2 then 2 or 1 then finish with course 3
 *
 * Approach (Topological Sort)
 * Given the courses [[1,0],[2,0],[3,1],[3,2]] sort topologically.
 * We have the following tree.      
 *      0        
 *    /   \
 *   1     2
 *    \    /
 *       3
 * Perform a depth first search and check for cycles, that is, no termination and return []
 *
 * Steps:
 * 1. Build an adjacency list.
 * 2. Perform a dfs with cycle detection and push elements to stack
 *    stack is [3, 2, 1, 0]
 * 3. This is the correct ordering [0, 1, 2, 3] or [0, 2, 1, 3]
 * 4. If a cycle exists, return [], eg [0, 1, 2, 1]
 */

import java.util.Collections;
import java.util.List;
import java.util.LinkedList;

class CourseScheduleII{
    private static boolean dfs(List<Integer>[] adj, int[] visited, List<Integer> stack, int v){
        visited[v] = 1;
        for(int u : adj[v]){
            if(visited[u] == 1) return true;
            if(visited[u] == 0 && dfs(adj, visited, stack, u)) return true;
        }
        visited[v] = 2;
        stack.add(v);
        return false;
    }
    public static int[] findOrder(int numCourses, int[][] prerequisites) {
        //Build adjacency list
        List<Integer>[] adj = new LinkedList[numCourses];
        for(int i = 0; i < numCourses; i++)
            adj[i] = new LinkedList<Integer>();
        for(int[] course : prerequisites)
            adj[course[1]].add(course[0]);
        
        //Create stack
        List<Integer> stack = new LinkedList<Integer>();
        int visited[] = new int[numCourses];
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0 && dfs(adj, visited, stack, i))
                return new int[0]; //cycle
        }
        //reverse stack
        Collections.reverse(stack);
        //convert to array
        int result[] = stack.stream().mapToInt(Integer::intValue).toArray();
        return result;
    }
    public static void printArr(int arr[]){
        for(int i = 0; i < arr.length; i++)
            System.out.print(i + " ");
        System.out.println();
    }
    public static void main(String[] args){
        int numCourses = 2;
        int prerequisites[][] = {{1, 0}};
        int numCourses1 = 4;
        int prerequisites1[][] = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
        int result[] = findOrder(numCourses, prerequisites);
        int result1[] = findOrder(numCourses1, prerequisites1);
        printArr(result);
        System.out.println();
        printArr(result1);
    }
}
