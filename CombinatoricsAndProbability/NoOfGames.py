"""n teams played a tournament and each team played with each other
find the number of games"""

"""
from itertools import combinations
for i in combinations("abced", 2):
    print("".join(i))
"""

#RECURSIVE
def T(n):
    if(n <= 1):
        return 0
    return (n-1) + T(n-1)

if __name__ == "__main__":
    n = int(input("No of Teams "))
    print(T(n))

