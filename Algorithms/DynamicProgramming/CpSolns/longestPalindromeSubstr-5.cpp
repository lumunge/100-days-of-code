// Leetcode #5 - Longest palindromic substring

#include<iostream>
#include<cstring>

using std::string;
using std::cout;
using std::endl;

class Solution{
    public:
        string longest(string str){
            int n = str.length();
            
            // create and fill dp table with 0s
            bool dp[n][n];
            memset(dp, 0, sizeof(dp));

            // fill diagonal for single characters - always palindrome
            for(int i = 0; i < n; i++)
                dp[i][i] = true;
            
            // left and right pointers
            int l = 0, r = 1; // single char string is palindrome
            // fill diagonal for two adjacent characters if palindrome
            for(int i = 0; i < n-1; i++){
                // if first two characters are palindrome
                if(str[i] == str[i+1]){
                    dp[i][i+1] = true;
                    l = i;
                    r = 2;
                }
            }

            // start from third character
            for(int i = 3; i <= n; i++){
                for(int j = 0; j < n - i + 1; j++){
                    int k = j + i - 1;
                    // if mid string is palindrome and border characters are same - it is palindrome
                    if(dp[j+1][k-1] && str[j] == str[k]){
                        dp[j][k] = true;
                        // if current substr > original
                        if(i > l){
                            // move pointers
                            l = j;
                            r = i;
                        }
                    }
                }
            }
            return str.substr(l, r);
        }
};

int main(){
    Solution soln;
    cout << soln.longest("babad") << endl;
    cout << soln.longest("aacabdkacaa") << endl;
    cout << soln.longest("cbbd") << endl;
    cout << soln.longest("b") << endl;
    cout << soln.longest("ab") << endl;
    cout << soln.longest("bb") << endl;
    cout << soln.longest("ccc") << endl;
    return 0;
}
