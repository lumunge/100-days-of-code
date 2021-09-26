#include<iostream>
using namespace std;

/* 
 * PROBLEM STATEMENT:
 * Given two strings s1, s2, return true, if s2 contains a permutation of s1,
 * false otherwise
 * true --> if s1 is a permutation of s2
 *
 * Sample:
 * Input: s1 = "abc"
 *        s2 = "ejkjkcbakiii"
 * Output: true;
 *
 * SampleII:
 * Input: s1 = "abc"
 *        s2 = "edejkkbcshak"
 * Output: false
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        int count[26] = {0}; //Init an array with zeros
        for(char c : s1)
            count[c - 'a'] += 1;
        int start = 0;
        //decrement coutn wjen found character
        for(int i = 0; i < s1.length(); ++i)
            count[s2[i] - 'a'] -= 1;
        //check if values of window are all 0s
        bool match = true;
        for(int c : count){
            if(c != 0){
                match = false;
                break;
            }
        }
        if(match) return true;
        //Shift start of window
        start++;
        while(start <= s2.length() - s1.length()){
            //sliding window
            int index1 = s2[start - 1] - 'a'; //index of first character in window
            int index2 = s2[start + s1.length() - 1] - 'a'; //index of last character in window
            count[index1] += 1; //for removed character
            count[index2] -= 1; //for new character
            match = true;
            for(int c : count){
                if(c != 0){
                    match = false;
                    break;
                }
            }
            if(match) return true;
            start++;
        }
        return false;
    }
};

int main(){
    Solution soln;
    string s1 = "ab";
    string s2 = "eidboaooo";
    cout << soln.checkInclusion(s1, s2) << endl;
    return 0;
}
