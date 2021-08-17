#include<iostream>
#include<vector>
using namespace std;

int MinRefills(vector<int> arr, int n, int l){
    int refills = 0;
    int currentRefill = 0;
    while(currentRefill <= n){
        int lastRefill = currentRefill;
        while(currentRefill <= n && (arr[currentRefill + 1] - arr[lastRefill]) <= l){
            currentRefill = currentRefill + 1;
        }
        if(currentRefill == lastRefill){
            return -1;
        }
        if(currentRefill <= n){
            refills += 1;
        }
    }
    return refills;
}

int main(){
    int m;
    int n;
    vector<int> arr;
    cin >> m;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << MinRefills(arr, n, m);
    return 0;
}
