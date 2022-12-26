""" 
PROBLEM STATEMENT:
Given a positive integer k, find the length of the smallest positive integr n such that
n is divisible by k and n only contains the digit 1.
Return length of n, otherwise return -1.

Sample:
Input: k = 3
Output: 3
Explanation: 111 / 3 

Input: k = 7
Output: 6
Explanation: 111111 / 7

Approach.
Initialize n as 0.
Intitialize i, represents how many times we add 1 to find a divisible number
also this is the length of n.
While int i is less than or equal to k:
    add '1's to n and divide by k,
    if result is divisible by k, return i
    otherwise increment i
"""

def SmallestDivisibleK(k):
    i = 1
    n = 0
    while(i <= k):
        n = (n * 10 + 1) % k
        if(n == 0):
            return i
        i += 1
    return -1

print(SmallestDivisibleK(1))
print(SmallestDivisibleK(3))
print(SmallestDivisibleK(7))
print(SmallestDivisibleK(9))
