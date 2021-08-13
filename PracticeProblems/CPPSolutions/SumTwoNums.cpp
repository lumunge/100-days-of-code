#include <iostream>
using namespace std;

long long int sumDigits(long long int a, long long int b){
    return a + b;
}

int main(){
    long long int num1;
    long long int num2;

    cout << "Number 1 \n";
    cin >> num1;
    cout << "Number 2 \n";
    cin >> num2;

    cout << sumDigits(num1, num2);

    return 0;

}
