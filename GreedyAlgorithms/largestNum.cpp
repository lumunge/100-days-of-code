#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<limits>
using namespace std;

int largestNum(int n, vector<int> arr){
    string result;
    n = arr.size();
    while(n > 0){
        float  maxDigit = -std::numeric_limits<float>::infinity();
        for(int i = 0; i < n; i++){
            if(i >= maxDigit){
                maxDigit = i;
            }
        }
        result.append(to_string(maxDigit));
        arr.erase(remove(arr.begin(), arr.end(), maxDigit), arr.end());
        n--;
    }
    stringstream res(result);
    int intNum = 0;
    res >> intNum;
    return intNum;
}

int main(){
    int n;
    int x;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
    cout << largestNum(n, arr);
    return 0;
}
