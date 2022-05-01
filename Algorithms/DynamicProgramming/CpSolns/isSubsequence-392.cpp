// Leetcode #352 - Is subsequence

#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

class Solution{
    public:
        bool isTrue(string s, string t){
            int m = s.length(), n = t.length();
            int j = 0;

            for(int i = 0; i < n and j < m; i++)
                if(s[j] == t[i]) j++; // move pointer

            return j == m;
        }
};

int main(){
    Solution soln;
    string s = "axc", t = "ahbgdc";
    string s1 = "abc", t1 = "ahbgdc";
    cout << soln.isTrue(s, t) << endl;
    cout << soln.isTrue(s1, t1) << endl;
    return 0;
}
