import random
import sys
import os

#Number of tests
tests = int(sys.argv[1])
#Parameters to run against script
n = int(sys.argv[2])
#Range of random numbers
m = int(sys.argv[3])

os.system("python3 genRandom.py " + str(n) + " " + str(m) + " > input.txt")
    
with open("input.txt") as fp:
    for i in fp:
        os.system("python3 change.py " + str(i))


