def fib(n):
    fibNumbers = [0, 1]
    if(n == 0):
        return 0
    if(n == 1):
        return 1
    for i in range(2, n+1):
        fibNumbers.append(fibNumbers[i-1] + fibNumbers[i-2])

    return fibNumbers[n]

if(__name__ == '__main__'):
    n = int(input())
    print(fib(n))




