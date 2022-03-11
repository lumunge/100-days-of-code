// Leetcode #91 - Decode ways

#include<iostream>
#include<string.h>

using std::string;
using std::cout; using std::endl;

class Solution{
    public:
        int decodings(string str){
            int n = str.length();
            if(n == 0 || str[0] == '0') return 0;
            // one possible decoding
            if(n == 1) return 1;
            // pointers
            int p1 = 1, p2 = 1;
            for(int i = 1; i < n; i++){
                int d = str[i] - '0'; // single number [1-9]
                int dd = (str[i-1] - '0') * 10 + d; // double number >= 10 num <= 26
                int count = 0;
                if(d > 0) count += p2;
                if(dd >= 10 && dd <= 26) count += p1;
                p1 = p2;
                p2 = count;
            }
            return p2;
        }
};

int main(){
    Solution soln;
    cout << soln.decodings("12") << endl;
    cout << soln.decodings("226") << endl;
    cout << soln.decodings("06") << endl;
    cout << soln.decodings("2626") << endl;
    cout << soln.decodings("1001") << endl;
    return 0;
}
