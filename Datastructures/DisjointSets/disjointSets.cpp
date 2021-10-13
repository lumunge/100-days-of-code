#include<iostream>
using namespace std;

class DisjointSet{
    private:
        int *rank, *parent, n;

    public:
        DisjointSet(int n){
            rank = new int[n];
            parent = new int[n];
            this->n = n;
            makeSet();
        }

        void makeSet(){
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x){
            if(parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void unionSet(int x, int y){
            int xSet = find(x);
            int ySet = find(y);
            if(xSet == ySet)
                return;
            if(rank[xSet] < rank[ySet])
                parent[xSet] = ySet;
            else if(rank[xSet] > rank[ySet])
                parent[ySet] = xSet;
            else{
                parent[ySet] = xSet;
                rank[xSet] = rank[xSet] + 1;
            }
        }
};

int main(){
    DisjointSet ds(5);
    ds.unionSet(0, 2);
    ds.unionSet(2, 4);
    ds.unionSet(1, 3);
    if(ds.find(4) == ds.find(0))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    if(ds.find(1) == ds.find(0))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}







