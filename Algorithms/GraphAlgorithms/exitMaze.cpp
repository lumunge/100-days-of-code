#include<iostream>
#include<vector>

using std::vector;
using std::pair;
using std::make_pair;
using std::cout;
using std::cin;
using std::endl;

/* ALGORITHM:
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
            visited[u] = true;
            for(int i = 0; i < vertices[u].size(); i++){
                int v = vertices[u][i];
                if(!visited[v])
                    explore(vertices, visited, v);
            }
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
