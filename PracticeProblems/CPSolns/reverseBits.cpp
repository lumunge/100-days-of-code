#include<iostream>
using namespace std;


/* 
 * PROBLEM STATEMENT:
 * Reverse bits of a given 32 bits unsigned integer
 * Input is a binary string of length 32
 *
 * Sample:
 * Input: 00000010100101000001111010011100
 * Output: 964176192 --> (00111001011110000010100101000000)
 *
 * Apporach 1:
 * Init result = 0;
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
    unsigned int n = 00000010100101000001111010011100;
    cout << soln.reverseBits(n) << endl;
    return 0;
}
