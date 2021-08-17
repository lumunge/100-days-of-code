#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string>

using namespace std;

bool isGreater(int a, int b){
    if((to_string(a).append(to_string(b))) > (to_string(b).append(to_string(a))))
        return true;
    return false;
}

int main(){
    string answer;
    vector<int> arr = {9, 4, 6, 1, 9};
    int n = arr.size();
    while(n != 0){
        //int maxDigit = *max_element(arr.begin(), arr.end());
        int maxDigit = -std::numeric_limits<int>::infinity();
        for(int i = 0; i < n; i++){
            if(isGreater(arr[i], maxDigit)){
                maxDigit = arr[i];
            }
        }
        answer.append(to_string(maxDigit));
        arr.erase(remove(arr.begin(), arr.end(), maxDigit), arr.end());
        n--;
    }
    cout << answer << endl;
    return 0;
}
