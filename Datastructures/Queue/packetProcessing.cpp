#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int main(){
    int i, j, k, t;
    int s, n;
    cin >> s >> n;
    queue<pair<int, pair<int, int>>> q;
    vector<pair<int, pair<int, int>>> v(n);
    vector<int> res(n);
    for(int i = 0; i < n; i++){
        cin >> j >> k;
        v[i] = make_pair(i, make_pair(j, k));
    }
    j = 0;
    while(j < n && j < s){
        q.push(v[j]);
        j++;
    }
    t = 0;
    while(!q.empty()){
        int st = max(t, q.front().second.first);
        t = st + q.front().second.second;
        res[q.front().first] = st;
        q.pop();
        while(q.size() < s && j < n){
            if(v[j].second.first < t){
                res[j++] -= 1;
            }else{
                q.push(v[j++]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << res[i] << endl;
    }
    return 0;
}
