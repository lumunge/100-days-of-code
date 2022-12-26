#include <iostream>
#include <vector>
using namespace std;

long long fib(int n){
    vector<long long int> fibNumbers;
    fibNumbers.push_back(0);
    fibNumbers.push_back(1);
    if(n == 0)
        return fibNumbers[0];
    if(n == 1)
        return fibNumbers[1];
    for(int i = 2; i <= n+1; i++)
        fibNumbers.push_back(fibNumbers[i-1] + fibNumbers[i-2]);
    return fibNumbers[n];
}

int main(){
    int n;
    cin >> n;
    long long result = fib(n);
    cout << result << endl;
    return 0;
}

