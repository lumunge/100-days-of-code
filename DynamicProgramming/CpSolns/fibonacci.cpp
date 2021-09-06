#include<iostream>
#include<vector>
using namespace std;


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

int main(){
    int n;
    cout << "Enter number: ", cin >> n;
    cout << fib(n) << endl;
    return 0;
}
