/* PROBLEM STATEMENT:
 * Given a directed graph with n vertices and m edges, compute the number of strongly
 * connected components.
 *
 * Input: n vertices, m edges
 *        for m edges, (u, v) vertices
 * Output: Number of strongly connected components;
 *
 * Sample:
 * Input: 4 4
 *        1 2
 *        4 1
 *        2 3
 *        3 1
 * Output: 2
 *
 * Explanation: {1, 3, 2} -> each vertex is reachable from another, {4} -> not reachable
 * from any other vertex.
 *
 * Approach:
 * Perform DFS on reverse graph and record post numbers.
 * Start exploration from the vertex with largest post number
 * 
 * dfs(reverse graph)
 * for v in V in reverse post-ordering
 *      if not visited(v)
 *      explore(v)
 *      count visited vertices
 *  return count;
*/

#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class StronglyConnectedComponents{
    private:

        void dfs(vector<vector<int>> graph, vector<bool> &visited, int v){
            if(visited[v]) return;
            visited[v] = true;
            for(auto i : graph[v]){
                if(!visited[i])
                    dfs(graph, visited, i);
            }
        }

        void rdfs(vector<vector<int>> rGraph, vector<bool> &visited, vector<int> &ordering, int v){
            if(visited[v]) return;
            visited[v] = true;
            for(auto i : rGraph[v]){
                if(!visited[i])
                    rdfs(rGraph, visited, ordering, i);
            }
            ordering.push_back(v);
        }

        vector<int> reversePostOrder(vector<vector<int>> rGraph){
            vector<int> ordering;
            vector<bool> visited;
            visited.resize(rGraph.size());
            for(int i = 0; i < rGraph.size(); i++){
                if(!visited[i])
                    rdfs(rGraph, visited, ordering, i);
            }
            reverse(ordering.begin(), ordering.end());
            return ordering;
        }

        int getScc(vector<vector<int>> graph, vector<vector<int>> rGraph){
            int components = 0;
            vector<bool> visited;
            visited.resize(graph.size());
            vector<int> rPostOrder = reversePostOrder(rGraph);
            for(auto i : rPostOrder){
                if(!visited[i]){
                    dfs(graph, visited, i);
                    components++;
                }
            }
            return components;
        }
    public:
        void run(){
            int n, m, u, v;
            cin >> n >> m;
            vector<vector<int>> graph(n, vector<int>());
            vector<vector<int>> rGraph(n, vector<int>());
            for(int i = 0; i < m; i++){
                cin >> u >> v;
                graph[u-1].push_back(v-1);
                rGraph[v-1].push_back(u-1);
            }
            cout << getScc(graph, rGraph) << endl;
        }
};

int main(){
    StronglyConnectedComponents scc;
    scc.run();
}
