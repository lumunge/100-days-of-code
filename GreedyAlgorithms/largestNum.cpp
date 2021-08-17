#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string>
#include<sstream>
using namespace std;

bool isGreater(int a, int b){
    if((to_string(a).append(to_string(b))) > (to_string(b).append(to_string(a))))
        return true;
    return false;
}

int getElement(int key, vector<int> arr){
    std::vector<int>::iterator it = std::find(arr.begin(), arr.end(), key);
    if (it != arr.end())
        return distance(arr.begin(), it);
    return -1;
}

int largestNum(int n, vector<int> arr){
    string answer;
    n = arr.size();
    while(n != 0){
        int maxDigit = -std::numeric_limits<int>::infinity();
        for(int i = 0; i < n; i++){
            if(isGreater(arr[i], maxDigit)){
                maxDigit = arr[i];
            }
        }
        answer.append(to_string(maxDigit));
        int elem = getElement(maxDigit, arr);
        arr.erase(arr.begin() + elem);
        n--;
    }
    stringstream res(answer);
    int result = 0;
    res >> result;
    return result;
}

int main(){
    int n;
    vector<int> arr;
    int x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
    cout << largestNum(n, arr) << endl;
    return 0;
}
