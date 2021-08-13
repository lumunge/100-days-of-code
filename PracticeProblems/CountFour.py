"""
PROBLEM STATEMENT
==> Calculate the number of occurrences of digit 4
    in decimal representation
"""

def getFour(n):
    nums = [x for x in str(n)]
    count = 0
    for i in nums:
        if(i == '4'):
            count += 1
    return count

if __name__ == "__main__":
    #test cases 
    T = int(input())
    for i in range(T):
        n = int(input())
        print(getFour(n))

