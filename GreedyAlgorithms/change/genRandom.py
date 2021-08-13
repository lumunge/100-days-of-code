import random
import sys

n = int(sys.argv[1])
seed = int(sys.argv[2])

for _ in range(n):
    print(random.randint(2, seed))
