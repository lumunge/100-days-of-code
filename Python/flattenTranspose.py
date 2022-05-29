# hackerrank -> https://www.hackerrank.com/challenges/np-transpose-and-flatten/
import numpy as np

if __name__ == "__main__":
    n, m = map(int, input().split())
    lst = np.array([input().strip().split() for _ in range(n)], int) 
    print(lst.transpose())
    print(lst.flatten())
