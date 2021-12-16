#include<iostream>
#include<vector>

using std::vector;
using std::pair;
using std::make_pair;
using std::cout;
using std::cin;
using std::endl;

/* 
 * PROBLEM STATEMENT:
 * Given an undirected graph and two distinct vertices u, v, check if there exists
 * a path between u,v.
 *
 * Sample:
 * Input: 4 4
 *        1 2
 *        3 2
 *        4 3
 *        1 4
 *        1 4
 * Output: true;
 * Explanation: A path exists between 1 and 4
 * 
 * ALGORITHM:
 *
 *   Explore(v):
 *       visited(v) <- true
 *       for (v, w) in E:
 *           if not visited(w):
 *               Explore(w)
 */


class ExploreGraph{
    private:
        void explore(vector<vector<int>> &vertices, vector<bool> &visited, int u){
            if(visited[u]) return;
            visited[u] = true;
            for(auto v : vertices[u])
                explore(vertices, visited, v);
        }

        bool isPath(vector<vector<int>> vertices, int x, int y){
            vector<bool> visited;
            visited.resize(vertices.size());
            explore(vertices, visited, x);
            return (visited[x] && visited[y]); 
        }

    public:
        void read(){
            int n, m, u, v, x, y;
            cin >> n >> m;
            vector<vector<int>> vertices(n, vector<int>());
            for(int i = 0; i < m; i++){
                cin >> u >> v;
                vertices[u-1].push_back(v-1);
                vertices[v-1].push_back(u-1);
            }
            cin >> x >> y;
            cout << isPath(vertices, x-1, y-1) << endl;
        }
};

int main(){
    ExploreGraph eg;
    eg.read();
    return 0;
}
