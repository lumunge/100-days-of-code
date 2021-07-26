"""
Implementation of algorithm to construct a number from 
chinese remainder theorem
ChinieseRemainderTheorem(n1, r1, n2, r2),
takes two coprime numbers n1, n2
and their respective remainders r1, r2
Returns r such that r < n1n2,
                    r === r1 mod n1
                    r === r2 mod n2
General Algorithm
=>  Use extended euclids algorithm to find x, y
    such that ax + by = 1
=>  n = ra*by + rb*ax  
"""

def ExtendedEuclid(a, b):
  #assert a >= b and b >= 0 and a + b > 0

  if b == 0:
    d, x, y = a, 1, 0
  else:
    (d, p, q) = ExtendedEuclid(b, a % b)
    x = q
    y = p - q * (a // b)

  assert a % d == 0 and b % d == 0
  assert d == a * x + b * y
  return (d, x, y)


def ChineseRemainderTheorem(n1, r1, n2, r2):
    (z, c, d) = ExtendedEuclid(n1, n2)
    
    ax, by = n1*c, n2*d
    #pairs = ((ax%n1), (ax%n2), (by%n1), (by%n2))

    n = r1*by + r2*ax 
    m = n1*n2
    
    return n%m

#print(ChineseRemainderTheorem(686579304, 295310485, 26855093, 8217207))








