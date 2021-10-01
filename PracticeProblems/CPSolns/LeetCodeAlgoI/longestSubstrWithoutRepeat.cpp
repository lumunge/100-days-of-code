#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int currentLen;
        int maxLen = 0;
        int st = 0;
        int start, i;
        //lst occurence of first character
        unordered_map<char, int> store;
        store[s[0]] = 0;
        for(i = 1; i < s.length(); i++){
            //if char not present in hashmap, add it
            if(store.find(s[i]) == store.end())
                store[s[i]] = i;
            else{
                //Char present in hashmap, has previous occurence
                //check if occurence is before or after starting point of substring
                if(store[s[i]] >= st){
                    //update  length of current substring
                    currentLen = i - st;
                    //update maxlength and start
                    if(maxLen < currentLen){
                        maxLen = currentLen;
                        start = st;
                    }
                    //next substring starts after last occurence of current character
                    st = store[s[i]] + 1;
                }
                //update last occurence of current character
                store[s[i]] = i;
            }
        }
        //compare length of last substring with maxlength
        //update maxlength and start
        if(maxLen < i - st){
            maxLen = i - st;
            start = st;
        }
        string longestSubStr = s.substr(start, maxLen);
        cout << longestSubStr << endl;
        return longestSubStr.length(); 
    }
};

int main(){
    Solution soln;
    string s = "abcabcbb";
    cout << soln.lengthOfLongestSubstring(s) << endl;
    return 0;
}




