// Leetcode #264 - Ugly number II

#include<iostream>
#include<vector>
#include<algorithm>

using std::vector; using std:: min;
using std::cout; using std::endl;

class Solution{
    public:
        int nthUgly(int n){
            int memo[n];
            memo[0] = 1;
            int counter = 1;
            int idx2 = 0, idx3 = 0, idx5 = 0;
            while(counter < n){
                int temp2 = memo[idx2] * 2, temp3 = memo[idx3] * 3, temp5 = memo[idx5] * 5;
                int next = min({temp2, temp3, temp5});
                // move pointers
                if(next == temp2) idx2++;
                if(next == temp3) idx3++;
                if(next == temp5) idx5++;
                memo[counter++] = next;
            }
            return memo[n-1];
        }
};

int main(){
    Solution soln;
    cout << soln.nthUgly(10) << endl;
    cout << soln.nthUgly(4) << endl;
    cout << soln.nthUgly(1) << endl;
    return 0;
}
