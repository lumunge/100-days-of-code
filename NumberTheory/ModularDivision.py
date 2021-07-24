"""
Given three integers a, b, and n,
such that gcd⁡(a,n) = 1  and n > 1,
the algorithm should return an integer x such that
0 ≤ x ≤ n − 1, 
and b/a = x (mod n)  (that is, b = ax (mod n).
"""
#MODULAR DIVISION

def gcd(a, b):
  assert a >= 0 and b >= 0 and a + b > 0

  while a > 0 and b > 0:
    if a >= b:
      a = a % b
    else:
      b = b % a
  return max(a, b)

def extended_gcd(a, b):
  if b == 0:
    d, x, y = a, 1, 0
  else:
    (d, p, q) = extended_gcd(b, a % b)
    x = q
    y = p - q * (a // b)

  assert a % d == 0 and b % d == 0
  assert d == a * x + b * y
  return (d, x, y)

def divide(a, b, n):
  assert n > 1 and a > 0 and gcd(a, n) == 1
  g, s, t = extended_gcd(a, n)
  x = b * s % n  
  # return the number x s.t. x = b / a (mod n) and 0 <= x <= n-1.
  return x
