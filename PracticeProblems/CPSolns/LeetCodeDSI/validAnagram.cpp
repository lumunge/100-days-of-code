#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

using std::unordered_map;
using std::string;
using std::cout;
using std::endl;

/*
 * PROBLEM STATEMENT:
 * Given two strings s and t, return true if it is an anagram false otherwise.
 *
 * Sample:
 * Input: s = "anagram" t = "nagaram"
 * Output: true
 *
 * Input: s = "hide" t = "run"
 * Output: false
 *
 * Approach 1:
 * Sort the strings and compare
 *
 * Approach 2:
 * Use two hash maps for each string, insert them into hashmap and compare the map
 */


class Solution{
    public:
        bool isAnagramI(string s, string t){
            sort(s.begin(), s.end());
            sort(s.begin(), s.end());
            return(s == t);
        }

        bool isAnagramII(string s, string t){
            unordered_map<char, int> smap;
            unordered_map<char, int> tmap;
            for(auto i:s)
                smap[i]++;
            for(auto i:t)
                tmap[i]++;
            return smap == tmap;
        }
};

int main(){
    Solution soln;
    string s = "rat";
    string t = "car";
    cout << soln.isAnagramI(s, t) << endl;
    cout << soln.isAnagramII(s, t) << endl;
    return 0;
}
