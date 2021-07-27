"""
Case e=2^k
Function that computes b^(2^k) mod m using only around 2k
modular multiplications
"""

def FastModularExponentiation(b, k, m):    
    c = b % m
    for _ in range(k):
        b = c ** 2 % m
    return b  


print(FastModularExponentiation(7, 4, 11))
print(FastModularExponentiation(7, 128, 11))


