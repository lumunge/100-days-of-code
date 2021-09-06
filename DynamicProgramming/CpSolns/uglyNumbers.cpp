#include<iostream>
#include<algorithm>
using namespace std;

/* PROBLEM STATEMENT
 * Get nth ugly number:
 * Numbers whose primes factors are 2, 3, 5
 */

class UglyNum{
public:
    int divide(int a, int b){
        while(a % b == 0)
            a = a / b;
        return a;
    }
    int isUgly(int n){
        n = divide(n, 2);
        n = divide(n, 3);
        n = divide(n, 5);
        if(n == 1)
            return 1;
        return 0;
    }
    int nthUglyNum(int n){
        int count = 1;
        int i = 1;
        while(n > count){
            i++;
            if(isUgly(i))
                count++;
                //cout << "isUgly(" << i << ")" << " count: " << count << endl;
        }
        return i;
    }
};

/* USING DYNAMIC PROGRAMMING
 * Declare an array of size n -> sizeo of input
 * i = 2, j = 3, k = 5
 * Range for 2 = 2, 4, 6, 8, 10, 12, 14, 16...
 * Range for 3 = 3, 6, 9, 12, 15, 18, 27...
 * Range for 5 = 5, 10, 15, 20, 25, 30, 35...
 * At each iteration select the minimum element of the three
 * Iteration:
 *           2 -> 3 -> 4 -> 5 -> 6 -> 8 -> 9 -> 10 -> 12 -> 14 -> 15 -> 16
 * Since all of the numbers will be multiples of either 2, 3, or 5;
 */

class UglyNumDP{
public:
    unsigned uglyNums(unsigned n){
        unsigned ugly[n];
        ugly[0] = 1;
        unsigned i = 0, j = 0, k = 0;
        unsigned nextOfTwo = 2;
        unsigned nextOfThree = 3;
        unsigned nextOfFive = 5;
        unsigned nextUglyNum = 1;
        for(int m = 1; m < n; m++){
            nextUglyNum = min(nextOfTwo, min(nextOfThree, nextOfFive));
            ugly[m] = nextUglyNum;
            if(nextUglyNum == nextOfTwo){
                i++;
                nextOfTwo = ugly[i] * 2;
            }
            if(nextUglyNum == nextOfThree){
                j++;
                nextOfThree = ugly[j] * 3;
            }
            if(nextUglyNum == nextOfFive){
                k++;
                nextOfFive = ugly[k] * 5;
            }
        }
        return nextUglyNum;
    }

};


int main(){
    UglyNumDP ugly;
    int n;
    cout << "Enter number: ", cin >> n;
    cout << ugly.uglyNums(n) << endl;
    return 0;
};




