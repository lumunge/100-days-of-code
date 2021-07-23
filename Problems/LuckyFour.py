"""
Proof that any four integers a, b, c, d.
There are two of them whose difference is
divisible by 3
"""

import random
import itertools as it

randomNums = []

for i in range(0, 4):
    n = random.randint(1, 100)
    randomNums.append(n)

combs = list(it.combinations(randomNums, 2))

print("Random Numbers : ", randomNums)

for i in combs:
    if((i[0] - i[1]) % 3 == 0):
        print("Sum of ", i[0], " and ", i[1], " : DIVISIBLE by 3")
    else:
        print("Sum of ", i[0], " and ", i[1], " : not divisible by 3")


