#include<iostream>
#include<map>
using namespace std;

/* 
    ITERATIVE ALGORITHM
long long factorial(int n){
    long long result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}
*/

//RECURSIVE ALGORITHM WITH MEMOIZATION

long long factorial(int n){
    map<int, int> memo;
    map<int, int>::iterator it;
    //base case
    if(n == 0){
        return 1;
    }
    memo[n] = n * factorial(n-1);
    it = memo.lower_bound(n);
    if(it == memo.end()){
        return 0;
    }else{
        return it->second;
    }
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}

