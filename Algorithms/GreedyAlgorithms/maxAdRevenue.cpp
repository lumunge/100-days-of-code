#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getIndex(vector<int> arr, int key){
    auto it = find(arr.begin(), arr.end(), key);
    if(it != arr.end()){
        int idx = it - arr.begin();
        return idx;
    }
    return -1;
}

int getTotal(vector<int> arr){
    int total = 0;
    for(int i = 0; i < arr.size(); i++){
        total += arr[i];
    }
    return total;
}

int getMaxAds(vector<int> profits, vector<int> clicks){
    vector<int> revenue;
    sort(profits.begin(), profits.end(), greater<int>());
    sort(clicks.begin(), clicks.end(), greater<int>());
    for(int i = 0; i < profits.size(); i++){
        revenue.push_back(profits[i] * clicks[i]);
    }
    return getTotal(revenue);
}


int main(){
    vector<int> profits;
    vector<int> clicks;
    int n;
    int p;
    int c;
    cin >> n;
    cout << "Profits" << endl;
    for(int i = 0; i < n; i++){
        cin >> p;
        profits.push_back(p);
    }
    cout << "Clicks" << endl;
    for(int i = 0; i < n; i++){
        cin >> c;
        clicks.push_back(c);
    }
    cout << getMaxAds(profits, clicks) << endl;
    return 0;
}


