#include<iostream>
using namespace std;

class Solution {
public:
    int indexOf(string s, char c){
        int found = s.find(c);
        if(found != string::npos)
            return found;
        return -1;
    }
    bool checkInclusion(string s1, string s2) {
        int j = 0;
        for(int i = 0; i < s2.length(); i++){
            if(s1[j] == s2[i]){
                cout << s1[j] << endl;
            }
        }
        return true; 
    }
};

int main(){
    Solution soln;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << soln.checkInclusion(s1, s2) << endl;
    return 0;
}
