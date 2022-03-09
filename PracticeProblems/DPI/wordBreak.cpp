// Leetcode #139 - Word break

#include<iostream>
#include<vector>
#include<unordered_set>
#include<string.h>

using std::unordered_set;
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Solution{
    private:
        // brute for recursive approach
        bool helper(unordered_set<string>& us, string &str, int start){
            int n = str.length();
            if(start == n) return true; // base case
            for(int i = start; i < str.length(); i++){
                // search in set
                if(us.count(str.substr(start, i - start + 1)))
                    // move to next position
                    if(helper(us, str, i+1)) return true;
            }
            return false;
        }

        // memoized solution
        int dp[10005]; // memo
        bool helperDP(unordered_set<string>& us, string &str, int start){
            int n = str.length();
            if(start == n) return true; // base case;
            if(dp[start] != -1) return dp[start];
            for(int i = start; i < n; i++){
                if(us.count(str.substr(start, i - start + 1)))
                    if(helperDP(us, str, i+1))
                        return dp[start] = 1; // memoize - 'true'
            }
            // if last value if false
            return dp[start] = 0;
        }

    public:
        bool wordBreak(vector<string>& dict, string str){
            unordered_set<string> us;
            // add words to set
            for(auto str : dict)
                us.insert(str);
            return helper(us, str, 0);
        }

        bool wordBreakDP(vector<string>& dict, string str){
            unordered_set<string> us;

            // create and fill memo array with -1
            memset(dp, -1, sizeof(dp));
            for(auto str : dict)
               us.insert(str);

            return helperDP(us, str, 0);
        }
};

int main(){
    Solution soln;
    vector<string> d = {"leet", "code"};
    string s = "leetcode";
    vector<string> d1 = {"apple", "pen"};
    string s1 = "applepenapple";
    vector<string> d2 = {"cats", "dog", "sand", "and", "cat"};
    string s2 = "catsandog";
    vector<string> d3 = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    string s3 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    cout << soln.wordBreakDP(d, s) << endl;
    cout << soln.wordBreakDP(d1, s1) << endl;
    cout << soln.wordBreakDP(d2, s2) << endl;
    cout << soln.wordBreakDP(d3, s3) << endl;
    return 0;
}
