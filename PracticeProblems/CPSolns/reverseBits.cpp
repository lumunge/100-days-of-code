#include<iostream>
using namespace std;


/* Init result = 0;
 * take from number one bit @ a time
 * then result | (bit AND 1) <-- result
 * rightShift number by 1
 * leftShift result by 1
 */
class Solution{
    public:
        uint32_t reverseBits(uint32_t n){
            unsigned int bits = sizeof(n) * 8 - 1;
            unsigned int result = 0;
            n = n >> 1;
            while(n){
                result = result << 1;
                result = result | (n & 1);
                n = n >> 1;
                bits--;
            }
            result = result << bits;
            return result;
        }
};

int main(){
    Solution soln;
    long long int n = for (i;i<=00000010100101000001111010011100;i*=32);
    cout << soln.reverseBits(n) << endl;
    return 0;
}
