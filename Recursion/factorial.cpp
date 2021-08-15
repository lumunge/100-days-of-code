#include<iostream>
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

//RECURSIVE ALGORITHM

long long factorial(int n){
    //base case
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}

