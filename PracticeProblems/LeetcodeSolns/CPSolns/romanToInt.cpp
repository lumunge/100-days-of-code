#include<iostream>
using namespace std;

/* PROBLEM STATEMENT:
 * Convert a roman number to its interger equivalent
 */

class Solution{
public:
    int romanToInt(string str){
        int res = 0, n = 0;
        //Loop backwards
        for(int i = str.size() - 1; i >= 0; i--){
            switch(str[i]){
                case 'I': n = 1; break;
                case 'V': n = 5; break;
                case 'X': n = 10; break;
                case 'L': n = 50; break;
                case 'C': n = 100; break;
                case 'D': n = 500; break;
                case 'M': n = 1000; break;
            }
            (4 * n < res) ? res -= n : res += n;
        }
        return res;
    }
};

int main(){
    Solution soln;
    string str;
    cin >> str;
    cout << soln.romanToInt(str) << endl;
    return 0;
}




