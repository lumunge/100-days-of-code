// Hackerrank Shortest reach - https://www.hackerrank.com/challenges/bfsshortreach/problem

#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using std::queue;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Graph{
    public:
        vector<vector<int>> adj; // adjacency matrix
        int V; // vertices
        
        Graph(int n){ // constructor
            adj = vector<vector<int>> (n, vector<int>());
            V = n;
        }
        
        void build(int u, int v){ // create graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> bfs(int start){// bfs algorithm
            vector<int> dist(V, INT_MAX); // distance
            vector<bool> visited(V, false); // visited nodes
            queue<int> q; // bfs queue
            
            dist[start] = 0;
            q.push(start);
            visited[start] = true;
            
            while(!q.empty()){
                int curr = q.front(); q.pop(); // process top element in queue
                for(int i = 0; i < adj[curr].size(); i++){
                    int neighbor = adj[curr][i];
                    if(!visited[neighbor] && dist[neighbor] > dist[curr] + 1){
                        // process neighbor
                        dist[neighbor]  = dist[curr] + 1;
                        q.push(neighbor);
                        visited[neighbor] = true;                    
                    }
                } 
            }
            
            return dist;
        }
        
        // get result
        vector<int> shortestReach(int start){
            vector<int> dist = bfs(start);
            for(int i = 0; i < V; i++){
                if(i != start){
                    if(dist[i] == INT_MAX)
                        dist[i] = -1;
                    else
                        dist[i] *= 6;       
                }
            }
            return dist;
        }
};

int main(){
    int queries;
    cin >> queries;
    
    for(int i = 0; i < queries; i++){
        int n, m;
        cin >> n;
        Graph graph(n);
        cin >> m;
        
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph.build(u, v);
        }
        
        int start;
        cin >> start;
        start--;
        
        vector<int> dist = graph.shortestReach(start);
        
        for(int i = 0; i < dist.size(); i++){
            if(i != start)
                cout << dist[i] << " ";
        }
        cout << endl;
    }
}
