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

    public:
        bool wordBreak(vector<string>& dict, string str){
            unordered_set<string> us;
            // add words to set
            for(auto str : dict)
                us.insert(str);
            return helper(us, str, 0);
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
    cout << soln.wordBreak(d, s) << endl;
    cout << soln.wordBreak(d1, s1) << endl;
    cout << soln.wordBreak(d2, s2) << endl;
    return 0;
}
