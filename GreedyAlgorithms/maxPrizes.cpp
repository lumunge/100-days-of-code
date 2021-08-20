#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void maxPrizes(int n){
    vector<int> list;
    vector<int> list2;
    int m = n;
    int decrement = 0;
    while(n > 0){
        n -= decrement;
        if(decrement > n || decrement == n)
            break;
        list.push_back(decrement);
        decrement += 1;
    }
    list.push_back(m - accumulate(list.begin(), list.end(), 0));
    for(int i = 0; i < list.size(); i++){
        list2.push_back(list[i]);
    }
    for(int i = 0; i < list2.size(); i++){
        cout << list2[i] << " ";
    }
    cout << endl;
} 


int main(){
    int n;
    cin >> n;
    maxPrizes(n);
    return 0;
}
