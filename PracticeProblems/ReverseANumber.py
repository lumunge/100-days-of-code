"""
PROBLEM STATEMENT
Given an integer, reverse it

1: get the integer an change into str -> list of objects
2: use reverse built in function to reverse the list
3: use join built in function to join list items together
4: use type casting to return the list as an integer

"""

def reverseInt(n):
    strN = str(n)
    intList = []
    for i in strN:
        intList.append(i) 
    intList.reverse()
    res = int("".join(intList))
    return res

# testcases
t = int(input())

for i in range(t):
    n = int(input())
    print(reverseInt(n))
