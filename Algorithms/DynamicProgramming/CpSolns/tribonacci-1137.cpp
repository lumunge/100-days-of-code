// Leetcode #1137 - N-th Tribonacci Number

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

class Tribonacci{
    public:
        int tribonacci(int n){
            vector<int> triNums = {0, 1, 1};
            for(int i = 3; i < n+1; i++)
                triNums.push_back(triNums[i-1] + triNums[i-2] + triNums[i-3]);
            return triNums[n];
        }
};

int main(){
    Tribonacci soln;
    cout << soln.tribonacci(4) << endl;
    cout << soln.tribonacci(25) << endl;
}
