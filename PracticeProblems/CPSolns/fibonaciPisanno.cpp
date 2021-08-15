#include <iostream>
#include <vector>

using namespace std;

//Pissano Period Function
int pisanoPeriod(int m){
    int prev = 0;
    int curr = 1;
    int sqM = m * m;
    int i;
    int res;
    for(i = 0; i <= sqM; i++)
        prev, curr = curr , (prev + curr) % m;
        if(prev == 0 && curr == 1)
            res = i + 1;
    return res;
}

//Fibonacci function
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

int fibModuloPisano(int n, int m){
    int pisanoNum = pisanoPeriod(m);
    int rem = n % pisanoNum;
    int res = fib(rem) % m;
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    int res = fibModuloPisano(n, m);
    cout << res;
    return 0;
}
