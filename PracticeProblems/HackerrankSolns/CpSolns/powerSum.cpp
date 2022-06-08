// Hackerrank - https://www.hackerrank.com/challenges/the-power-sum/

#include<iostream>
#include<cmath>

using std::cout;

class Solution{
    private:
        int helper(int x, int n, int z){
            int val = x - pow(z, n);
            if(val < 0)
                return 0;
            else if(val == 0)
                return 1;
            else
                return helper(val, n, z+1) + helper(x, n, z+1);
        }
    public:
        int powerSum(int x, int n){
            return helper(x, n, 1);
        }
};

int main(){
    Solution soln;
    cout << soln.powerSum(100, 2) << '\n';
    return 0;
}
