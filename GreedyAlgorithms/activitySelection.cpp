#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void printArr(vector<pair<int, int>> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i].first << " -> " << arr[i].second << endl;
    }
}

vector<pair<int, int>> selectActivity(vector<pair<int, int>> arr){
    vector<pair<int, int>> times;
    int j = 0;
    int n = arr.size();
    sort(arr.rbegin(), arr.rend());
    times.push_back(make_pair(arr[j].first, arr[j].second));
    for(int i = 0; i <= n; i++){
        if(arr[j].first - 1 == arr[i].second){
            times.push_back(make_pair(arr[i].first, arr[i].second));
            j += 1;
        }
    }

    printArr(times);
    return times;
}

int main(){
    vector<pair<int, int>> times;
    int n;
    cin >> n;
    for(int i =  0; i < n; i++){
        int start, end;
        cin >> start >> end;
        times.push_back(make_pair(start, end));
    }
    selectActivity(times);
    return 0;
}

