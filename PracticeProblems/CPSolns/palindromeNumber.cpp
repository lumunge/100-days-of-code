#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long reverseNum(int n){
        int rem;
        long long reversedNum = 0;
        while(n != 0){
            rem = n % 10;
            reversedNum = (reversedNum * 10) + rem;
            n /= 10;
        }
        return reversedNum;
    }
    bool isPalindrome(int x) {
        if(x >= 0 && reverseNum(x) == x)
            return true;
        return false;
    }
};


int main(){
    Solution soln;
    int n;
    cin >> n;
    cout << soln.isPalindrome(n) << endl;
    return 0;
}
