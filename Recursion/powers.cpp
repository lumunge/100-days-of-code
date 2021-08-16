#include<iostream>
using namespace std;

int isEven(int n){
    return n % 2 == 0;
}

int isOdd(int n){
    return !isEven(n);
}

int getPower(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 1 / getPower(x, -n);
    }
    if(isOdd(n) == true){
        return getPower(x, n-1) * x;
    }
    if(isEven(n) == true){
        int result = getPower(x, n/2);
        return result * result;
    }
    return 0;
}

int main(){
    int x, n;
    cin >> x >> n;
    cout << getPower(x, n) << endl;
    return 0;
}

