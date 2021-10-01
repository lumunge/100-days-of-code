#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Reverse the order of characters in each word within a sentenc while preverving 
 * whitespace and initial word order
 *
 * Sample:
 * Input: "God Ding"
 * Output: "doG, gniD"
 */

class Solution {
public:
    string reverseWords(string s){
        int l, r = 0;
        while(l < s.length()){
            while(r < s.length() && s[r] != ' ')
                r++;
            reverse(s.begin() + l, s.begin() + r);
            l = r + 1;
            r = l;
        }
        return s;
    }
};

int main(){
    Solution soln;
    string str = "Let's take Leetcode contest";
    cout << "\"" << soln.reverseWords(str) << "\"" << endl;
    return 0;
}
