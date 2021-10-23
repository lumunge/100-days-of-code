#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

/*
 * PROBLEM STATEMENT
 * Given a set of activities, along with the starting and finishing time of each activity,
 * find the maximum number of activities performed by a single person assuming that a 
 * person can only work on a single activity at a time
 * 
 */

//Print array
void printArr(vector<pair<int, int>> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i].first << " " << arr[i].second << endl;
    }
}

vector<pair<int, int>> selectActivity(vector<pair<int, int>> arr){
    vector<pair<int, int>> times;
    int j = 0;
    int n = arr.size();
    //sort array in descending order
    sort(arr.rbegin(), arr.rend());
    //Push last activity to times array
    times.push_back(make_pair(arr[j].first, arr[j].second));
    //go through the sorted array comparing elements
    //for first pair, if first element - 1 == second pair second element
    //push the pair the pair to times array
    for(int i = 0; i <= n; i++){
        if(arr[j].first - 1 == arr[i].second){
            times.push_back(make_pair(arr[i].first, arr[i].second));
            j += 2;
        }
    }
    //sort in descending order
    sort(times.begin(), times.end());
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
    printArr(selectActivity(times));
    return 0;
}

