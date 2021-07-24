"""
A function squares(n, m) that returns minimum number of same size
squares required to tile a grid of size n x m
"""

def gcd(a, b):
    assert a >= 0 and b >= 0 and a+b > 0

    while(a > 0 and b > 0):
        if(a >= b):
            a = a % b
        else:
            b = b % a
    
    return max(a, b)


def squares(n, m):
    g = gcd(n, m)
    
    while(n % g == 0 and m % g == 0):
        n = n // g
        m = m // g
        return n * m
