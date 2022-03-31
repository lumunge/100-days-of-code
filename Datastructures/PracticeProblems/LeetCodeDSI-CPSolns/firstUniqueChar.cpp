#include<iostream>
#include<unordered_map>
#include<string>

using std::unordered_map;
using std::string;
using std::cout;
using std::endl;

/* 
 * PROBLEM STATEMENT:
 * Given an string s, find the first non-repeating character and return its index,
 * otherwise return -1.
 *
 * Sample:
 * Input: s = "leetcode"
 * Output: 0
 *
 * Input: s = "aabb"
 * Output: -1
 *
 * Approach: O(n) time, loop string twice, O(1) space, letters cannot exceed 26
 * 1. Insert elements into a hashmap each with its count
 * 2. Loop though the string characters and perform an if check, if character count is 1
 *    break out of the loop and return index, otherwise return -1.
 *
 */

class Solution{
    public:
        int firstUniqChar(string s) {
            unordered_map<char, int> umap;
            for(int i = 0; i < s.length(); i++){
                umap[s[i]]++;
            }
            for(int i = 0; i < s.length(); i++){
                if(umap[s[i]] == 1)
                    return i;
            }
            return -1;
        }
};

int main(){
    Solution soln;
    string str = "leetcode";
    cout << soln.firstUniqChar(str) << endl;
    return 0;
}
