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

if(__name__ == '__main__'):
    a, b = map(int, input().split())
    print(lcm(a, b))


