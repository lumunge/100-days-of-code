#include<iostream>
using namespace std;

/* 
 * PROBLEM STATEMENT:
 * Given an integer n, return true if its a power of 2 else return false
 * Solve without using a loop
 *
 * Sample: 
 * Input: n = 16
 * Output: true
 *
 * Input: n = 24
 * Output: false
 *
 * BITWISE OPERATIONS:
 * 
 * --------------------------------
 *           AND   OR    XOR   NOT
 * | x | y | x&y | x|y | x^y | ~x |
 * | 0 | 0 |  0  |  0  |  0  |  1 |
 * | 0 | 1 |  0  |  1  |  1  |  1 |
 * | 1 | 0 |  0  |  1  |  1  |  0 |
 * | 1 | 1 |  1  |  1  |  0  |  0 |
 * --------------------------------
 */

class Solution{
    public:
        //Using loop
        bool isPowerTwo(int n){
            if(n == 0)
                return false;
            while(n % 2 == 0)
                n /= 2;
            return (n == 1 ? true : false);
        }
        //Using bitwise operations
        bool isPowerTwoII(int n){
            if(n == 0)
                return false;
            return ((n & n - 1) == 0);
        }
};

int main(){
    Solution soln;
    int n = 24;
    int n2 = 32;
    cout << soln.isPowerTwoII(n) << endl;
    cout << soln.isPowerTwoII(n2) << endl;
}
