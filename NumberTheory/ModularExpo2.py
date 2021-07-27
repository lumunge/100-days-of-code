"""
Abrbitrary e
Function that computes b^e mod m using 2log2e modular multiplications
"""


def FastModularExponentiation(b, e, m):
    
    x = 1
    if 1 & e:
        x = b
    while e:
        e >>= 1
        b = (b*b) % m
        if(e & 1):
                x = (x*b) % m
    return x 

print(FastModularExponentiation(7, 4, 11))
print(FastModularExponentiation(7, 128, 11))



