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
