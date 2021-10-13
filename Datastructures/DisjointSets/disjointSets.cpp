#include<iostream>
using namespace std;

class DisjointSet{
    private:
        int *rank;
        int *parent;
        int n;
    public:
        //constructor
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

        int find(int i){
            if(parent[i] != i)
                parent[i] = find(parent[i]);
            return parent[i];
        }

        void unionSet(int i, int j){
            int i_id = find(i);
            int j_id = find(j);
            if(i_id == j_id)    // they are equal
                return;
            if(i_id < j_id)     // place smaller under larger
                parent[i_id] = j_id;
            else if(i_id > j_id)
                parent[j_id] = i_id;
            else{
                parent[i_id] = j_id;
                rank[i_id] = rank[i_id] + 1;
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
