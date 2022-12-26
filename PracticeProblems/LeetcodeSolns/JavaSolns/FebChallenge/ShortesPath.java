// Leetcode #847 -  Shortest path visiting all nodes

import java.util.ArrayList;

class ShortestPath{
    static int shortPath(int[][] graph){
        if(graph.length == 1) return 0;
        
        int n = graph.length;
        int endMask = (1 << n) - 1;
        boolean[][] visited = new boolean[n][endMask];
        ArrayList<int[]> queue = new ArrayList<>();
        
        for(int i = 0; i < n; i++){
            queue.add(new int[] {i, 1 << i});
            visited[i][1 << i] = true;
        }
        
        int steps = 0;
        while(!queue.isEmpty()){
            ArrayList<int[]> queue1 = new ArrayList<>();
            for(int i = 0; i < queue.size(); i++){
                int[] curr = queue.get(i);
                int node = curr[0], mask = curr[1];
                for(int neighbor : graph[node]){
                    int mask1 = mask | (1 << neighbor);
                    if(mask1 == endMask) return 1 + steps;
                    if(!visited[neighbor][mask1]){
                        visited[neighbor][mask1] = true;
                        queue1.add(new int[] {neighbor, mask1});
                    }
                }
            }
            steps += 1;
            queue = queue1;
        }
        return -1;
    }

    public static void main(String[] args){
        int[][] g1 = {{1, 2, 3}, {0}, {0}, {0}};
        int[][] g2 = {{1},{0,2,4},{1,3,4},{2},{1,2}};
        System.out.println(shortPath(g1));
        System.out.println(shortPath(g2));
    }
}
