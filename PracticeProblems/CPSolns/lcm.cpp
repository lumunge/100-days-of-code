#include <iostream>
#include<assert.h>
using namespace std;

long long int gcd(long long int a, long long int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    while( a > 0 && b > 0)
        if(a >= b)
            a = a % b;
        else
            b = b % a;
    return max(a, b);
}

long long int lcm(long long int a, long long int b){
    long long int div = gcd(a, b);
    long long int prod = a * b;
    return prod / div;
}

int main(){
    long long int a, b;
    cin >> a >> b;
    long long int result = lcm(a, b);
    cout << result << endl;
   return 0;
}

