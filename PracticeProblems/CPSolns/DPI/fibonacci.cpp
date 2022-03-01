// Leetcode #509 - Fibonacci Number

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

class Fibonacci{
    public:
        int fib(int n){
            vector<int> fibNums = {0, 1};
            for(int i = 2; i < n+1; i++)
                fibNums.push_back(fibNums[i-1] + fibNums[i-2]);

            return fibNums[n];
        }
};

int main(){
    Fibonacci soln;
    cout << soln.fib(2) << endl;
    cout << soln.fib(3) << endl;
    cout << soln.fib(18) << endl;
    return 0;
}
