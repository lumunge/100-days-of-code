#include<iostream>
#include<cmath>
using namespace std;

/* PROBLEM STATEMENT
 * Printing the prime factors of a number
 */
class PrimeFactors{
public:
    void getPrimeFactors(int n){
        while(n % 2 == 0){
            cout << 2 << endl;
            n = n / 2;
        }
        // n is odd
        for(int i = 3; i < sqrt(n); i+=2){
            while(n % i == 0){
                cout << i << endl;
                n = n / i;
            }
        }
        // n can no longer be divided, print n
        if(n > 2){
            cout << n << endl;
        }
    }
};
int main(){
    PrimeFactors prime;
    int n;
    cout << "Enter number: ", cin >> n;
    prime.getPrimeFactors(n);
    cout << endl;
    return 0;
}
