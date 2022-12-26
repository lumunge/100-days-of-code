#include<iostream>
#include<bitset>
#include<bits/stdc++.h>

using std::bitset;
using std::cout;

int main(){
    int x = -43;
    bitset<32> y(x);
    cout << y << '\n';
    unsigned int z = y.to_ulong();
    cout << z << '\n';
    return 0;
}
