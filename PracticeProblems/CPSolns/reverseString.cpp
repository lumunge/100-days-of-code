#include<iostream>
#include<vector>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Reverse a sting, without allocating extra space for another array,
 * Using in-place shifting of elements O(1)
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int j = s.size()-1;
        for(int i = 0; i < s.size()/2; i++){
            swap(s[i], s[j]);
            j--;
        }
        cout << endl;
    }
};


int main(){
    Solution soln;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    soln.reverseString(s);
    for(int i = 0; i < s.size(); i++){
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}
