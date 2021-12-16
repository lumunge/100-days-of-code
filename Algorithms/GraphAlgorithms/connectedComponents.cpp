#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

/* 
 * PROBLEM STATEMENT:
 * Return count of connected components in a graph
 * Input: n vertices and m edges
 * Output: Number of connected components.
 *
 * Sample:
 * Input: 4 2
 *        1 2
 *        3 2
 * Output: 2
 */

class Solution{
    private:
        void explore(vector<vector<int>> &vertices, vector<bool> &visited, int u){
            if(visited[u]) return;
            visited[u] = true;
            for(auto v : vertices[u]){
                explore(vertices, visited, v);
            }
        }

        int dfs(vector<vector<int>> vertices){
            int count = 0;
            vector<bool> visited;
            visited.resize(vertices.size());
            for(int i = 0; i < vertices.size(); i++){
                if(!visited[i]){
                    explore(vertices, visited, i);
                    count++;
                }
            }
            return count;
        }

    public:
        void read(){
            int n, m, a, b;
            cin >> n >> m;
            vector<vector<int>> vertices(n, vector<int>());
            //build adj-matrix
            for(int i = 0; i < m; i++){
                cin >> a >> b;
                vertices[a-1].push_back(b-1);
                vertices[b-1].push_back(a-1);
            }
            cout << dfs(vertices) << endl;
        }
};

int main(){
    Solution soln;
    soln.read();
    return 0;
}
