#include <iostream>
#include<assert.h>
using namespace std;

int gcd(int a, int b){
    assert(a > 0 || b > 0);
    if(a == 0)
        return b;
    else if(b == 0)
        return a;
    while(a > 0 && b > 0){
        if(a >= b){
            a = a % b;
        }else{
            b = b % a;
        }
    }
    return max(a, b);
}

int main(){
    int a, b;
    cin >> a >> b;
    int result = gcd(a, b);
    cout << result << endl;
    return 0;
}

