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
