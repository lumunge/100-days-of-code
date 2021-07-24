"""
#NAIVE APPROACH

def lcm(a, b):
    assert a > 0 and b > 0

    for i in range(1, a*b + 1):
        if(i % a == 0 and i % b == 0):
            return i

#Slower for larger numbers
#print(lcm(531441, 262144))
"""

#EUCLIDS ALGORITHM

def gcd(a, b):
  assert a >= 0 and b >= 0 and a + b > 0

  while a > 0 and b > 0:
    if a >= b:
      a = a % b
    else:
      b = b % a

  return max(a, b)

def lcm(a, b):
    assert a > 0 and b > 0
    return a*b // gcd(a, b)
