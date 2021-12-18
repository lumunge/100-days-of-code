#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

/* 
 * PROBLEM STATEMENT:
 * Given a graph, return true is it contains a cycle, otherwise false.
 * 
 * Input: n vertices and m edges, for each m, we have u,v representing edges
 * Output: true if there is a cycle, false otherwise
 *
 * Sample:
 * Input: 4 4
 *        1 2
 *        4 1
 *        2 3
 *        3 1
 * Output: true
 * Explanation: Cycle exists 1->2->3->1
 */

class CheckCycle{
    private:
        bool cycle = false;
        void dfs(vector<vector<int>> graph, vector<bool> visited1, vector<bool> visited2, int v){
            visited1[v] = true;
            visited2[v] = true;
            for(auto i : graph[v]){
                if(!visited1[i])
                    dfs(graph, visited1, visited2, i);
                else if(visited2[i]){
                    cycle = true;
                    return;
                }
            }
            visited2[v] = false;
        }

        //check for cycle
        bool hasCycle(vector<vector<int>> graph){
            vector<bool> visited1;
            vector<bool> visited2;
            visited1.resize(graph.size());
            visited2.resize(graph.size());
            for(int i = 0; i < graph.size(); i++){
                if(cycle) break;
                if(!visited1[i])
                    dfs(graph, visited1, visited2, i);
            }
            return cycle ? 1 : 0;
        }
    public:
        void read(){
            int n, m, u, v;
            cin >> n >> m;
            vector<vector<int>> graph(n, vector<int>());
            for(int i = 0; i < m; i++){
                cin >> u >> v;
                graph[u-1].push_back(v-1); 
                //graph[v-1].push_back(u-1);
            }
            cout << hasCycle(graph) << endl;
        }
};

int main(){
    CheckCycle cc;
    cc.read();
    return 0;
}
