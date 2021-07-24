"""
BRUTE FORCE SOLN
def gridTraveller(m, n):
    if m == 1 and n == 1: return 1
    if m == 0 or n == 0: return 0
    return gridTraveller(m-1, n) + gridTraveller(m, n-1)
"""

#MEMOIZED SOLN
def gridTraveller(m, n, memo={}):
    key = m, ',', n
    if key in memo: return memo[key]
    if m == 1 and n == 1: return 1
    if m == 0 or n == 0: return 0
    memo[key] = gridTraveller(m-1, n, memo) + gridTraveller(m, n-1, memo)
    return memo[key]

#test cases
T = int(input())

for i in range(T):
    m, n = map(int, input().split())
    print(gridTraveller(m, n))
