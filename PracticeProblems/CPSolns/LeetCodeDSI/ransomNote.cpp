#include<iostream>
#include<unordered_map>
#include<string>

using std::unordered_map;
using std::string;
using std::cout;
using std::endl;

/*
 * PROBLEM STATEMENT:
 * Given two strings, ransomNote and magazine, return true if ransomNote can be
 * constructued from magazine, else return false.
 *
 * Sample:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 *
 * Input: ransomNote = "aa" magazine = "ab"
 * Output: false
 *
 * Approach:
 * Create two hashmaps of each string.
 * Loop through ransom note, if the frequency of its characters in the magazine is
 * greater, return false, otherwise true.
 */

class Solution{
    public:
        bool canConstruct(string ransomNote, string magazine){
            unordered_map<char, int> rmap;
            unordered_map<char, int> mmap;
            int n = ransomNote.length();
            int m = magazine.length();
            
            if(n > m)
                return false;

            for(int i = 0; i < n; i++){
                rmap[ransomNote[i]]++;
            }

            for(int i = 0; i < m; i++){
                mmap[magazine[i]]++;
            }
            
            for(int i = 0; i < n; i++){
                if(rmap[ransomNote[i]] > mmap[ransomNote[i]])
                    return false;
            }
            return true;
        }
};

int main(){
    Solution soln;
    string ran = "aa";
    string mag = "ab";
    cout << soln.canConstruct(ran, mag) << endl; 
    return 0;
}
