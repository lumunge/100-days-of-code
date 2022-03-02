// Leetcode #70 - climbing stairs

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

class ClimbingStairs{
    public:
        int climb(int n){
            vector<int> steps = {0, 1, 2};
            if(n <= 2) return steps[n];
            for(int i = 3; i <= n; i++)
                steps.push_back(steps[i-1] + steps[i-2]);
            return steps[n];
        }
};

int main(){
    ClimbingStairs soln;
    cout << soln.climb(10) << endl;
    cout << soln.climb(2) << endl;
    cout << soln.climb(3) << endl;
    return 0;
}
