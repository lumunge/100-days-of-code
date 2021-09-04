#include<iostream>
#include<limits.h>
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

    int reversed(int x){
        int reversedNum = 0;
        while(x != 0){
            int rem = x % 10;
            x /= 10;
            if(reversedNum > INT_MAX/10 || (reversedNum == INT_MAX / 10 && rem > 7)) return 0;
            if(reversedNum < INT_MIN/10 || (reversedNum == INT_MIN / 10 && rem < -8)) return 0;
            reversedNum = reversedNum * 10 + rem;
        }
        return reversedNum;
    }
};

int main(){
    Solution soln;
    int n;
    cout << "Enter number: ", cin >> n;
    cout << soln.reversed(n) << endl;
    return 0;
}
