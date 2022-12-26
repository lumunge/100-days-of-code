"""
PROBLEM STATEMENT:
Given an integer, give its complement.
Sample:
Input: num = 5;
Output: = 2
Explanation: 5 = 101
             2 = 010

Approch:(XOR with 1)
1 xor 1 = 0
0 xor 1 = 1
"""

import math

def complement(num):
    if(num == 0):
        return 1
    #get number of bits
    bits = num.bit_length()
    #get mask
    mask = (1 << bits) - 1 
    return num ^ mask

print(complement(5))
print(complement(0))
