#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

float vw(float a, float b){
    return a / b;
}

void printArr(vector<pair<float, float>> arr){
    float valWt;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i].first << " " << arr[i].second << " " << vw(arr[i].second, arr[i].first) << " ";
        cout << endl;
    }
}

bool sortByVw(const pair<float, float> &a, const pair<float, float> &b){
    return vw(a.first, a.second) < vw(b.first, b.second); 
}

int main(){
    vector<pair<float, float>> weightValue;
    int W;
    int w;
    int v;
    int n;
    float total = 0.0;
    cout << "Pairs ----- Max Weight" << endl;
    cin >> n >> W;
    for(int i = 0; i < n; i++){
        cout << "Weight ----- Value" << i+1 << endl;
        cin >> w >> v;
        weightValue.push_back(make_pair(w, v));
    }
    sort(weightValue.begin(), weightValue.end(), sortByVw);
    while(W > 0){
        for(int i = 0; i < weightValue.size(); i++){
            if(weightValue[i].first > W){
                total += (weightValue[i].second / weightValue[i].first) * W;
                W -= W;
            }else{
                total += weightValue[i].second;
                W -= weightValue[i].first;
            }
        }
    }
    cout << total << endl;
    return 0;
}





