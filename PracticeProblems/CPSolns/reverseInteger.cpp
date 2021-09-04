#include<iostream>
#include<sstream>
using namespace std;

class Solution{
public:
    long long reverse(long long n){
        long long reversedNum = 0;
        int rem;
        while(n != 0){
            rem = n % 10;
            reversedNum = reversedNum * 10 + rem;
            n /= 10;
        }
        return reversedNum;
    }
};

int main(){
    Solution soln;
    int n;
    cout << "Enter number: ", cin >> n;
    cout << soln.reverse(n) << endl;
    return 0;
}
