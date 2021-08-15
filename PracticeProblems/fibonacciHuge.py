"""
PROBLEM STATEMENT
Compute Fn modulo m, m upto 10^14
"""

def pisanoPeriod(m):
    #Get pissano period
    #Length of pissano period for a given m from 3 to m*m
    prev, curr = 0, 1
    for i in range(0, m * m):
        prev, curr = curr, (prev + curr) % m

        if(prev == 0 and curr == 1):
            return i + 1


def fib(n):
    nums = [0, 1]
    if(n == 0):
        return 0
    if(n == 1):
        return 1
    for i in range(2, n+1):
        nums.append(nums[i-1] + nums[i-2])
    return nums[n]

def fibModuloPisano(n, m):
    pisanoNum = pisanoPeriod(m)
    remByPisano = n % pisanoNum
    res = fib(remByPisano) % m
    return res

if(__name__ == "__main__"):
    n, m = map(int, input().split())
    print(fibModuloPisano(n, m))






