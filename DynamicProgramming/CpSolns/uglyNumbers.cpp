#include<iostream>
#include<vector>
using namespace std;

class UglyNumber{
public:
    int maxDivide(int a, int b){
        while(a % b == 0)
            a /= b;
        return a;
    }
    int isUgly(int n){
        n = maxDivide(n, 2);
        n = maxDivide(n, 3);
        n = maxDivide(n, 5);
        if(n == 1)
            return 1;
        return 0;
    }
    int nthUglyNum(int n){
        int i = 1;
        int count = 1;
        while(n > count){
            i++;
            if(isUgly(i)){
                count++;
            }
        }
        return i;  
    }
};


int main(){
    UglyNumber ugly;
    int n;
    cout << "Enter number: ", cin >> n;
    cout << ugly.nthUglyNum(n) << endl;
    return 0;
}
