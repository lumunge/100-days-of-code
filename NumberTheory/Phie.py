"""
Euler’s totient function 𝜙(n) counts integers between 0 and n − 1 
which are coprime with n

Coprime ==> {When GCD(m, n) = 1}
"""

def gcd(a, b):
  assert a >= 0 and b >= 0 and a + b > 0

  while a > 0 and b > 0:
    if a >= b:
      a = a % b
    else:
      b = b % a

  return max(a, b)

def PhieNums(n):
    phieNums = []
    for i in range(n):
        if(gcd(i, n) == 1):
            phieNums.append(i)
    return len(phieNums)

#print(PhieNums(77))
