#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Climbing a staircase takes n steps to reach top.
 * Each time you either climb 1 or 2 strps, how many distinct ways can you
 * climb to top
 */

class Solution{
    public:
        int climbStairs(int n){
            assert(n >= 0);
            vector<int> steps = {0, 1, 2};
            if(n <= 0)
                return n;
            for(int i = 3; i <= n; i++){
                steps.push_back(steps[i-1] + steps[i-2]);
            }
            return steps[n];
        }
        int climbStairsII(int n){
            if(n <= 2)
                return n;
            int x = 1, y = 2;
            for(int i = 3; i < n; ++i){
                int temp = y;
                y += x;
                x = temp;
            }
            return (x+y);
        }
};

int main(){
    Solution soln;
    int n1 = 2;
    int n2 = 3;
    cout << soln.climbStairs(n1) << endl;
    cout << soln.climbStairs(n2) << endl;
    cout << soln.climbStairsII(n1) << endl;
    cout << soln.climbStairsII(n2) << endl;
    return 0;
}
