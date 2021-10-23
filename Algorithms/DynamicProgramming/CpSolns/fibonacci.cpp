#include<iostream>
#include<vector>
using namespace std;

/* NOTES:
 * Solved by tabulation method:
 * Soution was derived by computing fib(0), fib(1) .... fib(n) and returning last entry to fibNums table.
 */

// Fibonacci By Tabulation
long long fib(int n){
    vector<int> fibNums = {0, 1};
    if(n == 0)
        return fibNums[0];
    if(n == 1)
        return fibNums[1];
    for(int i = 2; i <= n; i++)
        fibNums.push_back(fibNums[i-1] + fibNums[i-2]);
    return fibNums[n];
}

// Fibonacci by memoization
#define NIL -1
#define MAX 100
class fibTab{
public:
    //Initializing lookup table values as NIL
    int lookup[MAX];

    void init(){
        for(int i = 0; i < MAX; i++){
            lookup[i] = NIL;
        }
    }

    long long fib(int n){
        if(lookup[n] == NIL){
            if(n <= 1)
                lookup[n] = n;
            else
                lookup[n] = fib(n-1) + fib(n-2);
        }
        return lookup[n];
    }
};

int main(){
    fibTab fib;
    fib.init();
    int n;
    cout << "Enter number: ", cin >> n;
    cout << fib.fib(n) << endl;
    return 0;
}
