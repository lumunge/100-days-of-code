"""
ax + by = c 
Has a solution iff gcd(a,b) is divisible by c
"""
def gcd(a, b):
  assert a >= 0 and b >= 0 and a + b > 0

  while a > 0 and b > 0:
    if a >= b:
      a = a % b
    else:
      b = b % a

  return max(a, b)


def extended_gcd(a, b):
  assert a >= b and b >= 0 and a + b > 0

  if b == 0:
    d, x, y = a, 1, 0
  else:
    (d, p, q) = extended_gcd(b, a % b)
    x = q
    y = p - q * (a // b)

  assert a % d == 0 and b % d == 0
  assert d == a * x + b * y
  return (d, x, y)


def diophantine(a, b, c):
    assert c % gcd(a, b) == 0
    m, n, o = extended_gcd(a, b)
    x, y = 0, 0
    
    for i in range(-100, 100):
        if((i*m) == c):
            x = i*n
            y = i*o

    return (x, y)

print(diophantine(10, 6, 14))
print(diophantine(391, 299, -69))
print(diophantine(7, 5, 31))
