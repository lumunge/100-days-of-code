/* PROBLEM STATEMENT:
 * Compute the topological ordering of a given acyclic graph with n vertices and m edges
 *
 * Input: n vertices and m edges
 *        for each m, (u, v) representing edges from u to v.
 * Output: A topoligical ordering of its vertices.
 *
 * Sample:
 * Input: 4 3
 *        1 2
 *        4 1
 *        3 1
 * Output: 4 3 1 2
 *
 * Input: 4 1
 *        3 1
 * Output: 2 3 1 4
 *
 * Algorithm:
 * DFS(G)
 * Sort vertices by reverse post order.
 */

#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

class TopologicalSort{
    private:
        void dfs(vector<vector<int>> graph, vector<bool> visited, vector<int> &ordering, int v){
            if(visited[v]) return;
            visited[v] = true;
            for(auto i : graph[v])
                dfs(graph, visited, ordering, i);
            if(find(ordering.begin(), ordering.end(), v) == ordering.end())
                ordering.push_back(v);
        }

        vector<int> sort(vector<vector<int>> graph){
            vector<bool> visited;
            vector<int> ordering;
            visited.resize(graph.size());
            for(int i = 0; i < graph.size(); i++)
                dfs(graph, visited, ordering, i);
            reverse(ordering.begin(), ordering.end());
            return ordering;
        }

        void printVec(vector<int> vec){
            for(int i = 0; i < vec.size(); i++)
                cout << vec[i]+1 << " ";
            cout << endl;
        }

    public:
        void read(){
            int n, m, u, v;
            cin >> n >> m;
            vector<vector<int>> graph(n, vector<int>());
            for(int i = 0; i < m; i++){
                cin >> u >> v;
                graph[u-1].push_back(v-1);
            }
            vector<int> ts = sort(graph);
            printVec(ts);
        }
};
int main(){
    TopologicalSort ts;
    ts.read();
    return 0;
}
