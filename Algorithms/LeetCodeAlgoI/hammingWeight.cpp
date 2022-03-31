#include<iostream>
#include<bitset>
using namespace std;

/*
 * PROBLEM STATMENT:
 * Write a function that takes an unsigned int and returns number of '1' bits
 *
 * Sample:
 * Input: n = 00000000000000000000000000001011  //binary string of len 32
 * Output: 3
 */

class Solution{
    public:
        //Set mask to 1, loop 32 times and do and AND
        //if result == 1, current bit == 1, add count
        int hammingWeight(uint32_t n){
            int count = 0;
            unsigned int m = 1;
            for(int i = 0; i < 32; i++){
                if(m & n)
                    count++;
                m = m << 1;
            }
            return count;
        }
        //Brian Kernighan Algo:
        int hammingWeightII(uint32_t n){
            int count = 0;
            //repeat until get 0
            while(n != 0){
                n = n & (n-1);
                count++;
            }
            return count;
        }
};

int main(){
    Solution soln;
    unsigned int n =  00000000000000000000000000001011;
    unsigned int n2 = 00000000000000000000000010000000;
    //unsigned int n3 = 11111111111111111111111111111101;
    cout << soln.hammingWeightII(n) << endl;
    //cout << soln.hammingWeight(n2) << endl;
    //cout << soln.hammingWeight(n3) << endl;
    return 0;
}
