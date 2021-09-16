#include<iostream>
#include<vector>
using namespace std;

/*
 * PROBLEM STATEMENT
 * Write a function to find the longest common prefix string amonst an array of strings
 * Else return empty string ""
 *
 * Sample:
 * strs = ["flower", "flow", "flight"]
 * longestCommongPrefix(strs) --> "fl"
 *
 */

class Solution {
public:
    int getMinLength(vector<string> strs){
        int min = strs[0].length();
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].length() < min)
                min = strs[i].length();
        }
        return min;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int minLen = getMinLength(strs);
        string result;
        char current;
        for(int i = 0; i < minLen; i++){
            current = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != current)
                    return result;
            }
            result.push_back(current);
        }
        return result;
    }
};

int main(){
    Solution soln;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << soln.longestCommonPrefix(strs) << endl;
    return 0;
}
