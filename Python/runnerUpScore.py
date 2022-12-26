# Problem link -> https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/
def runnerScore(arr):
    max1 = max(arr)
    max2 = []
    for i in arr:
        if(i != max1):
            max2.append(i)
    return max(max2)

if __name__ == '__main__':
    n = int(raw_input())
    arr = map(int, raw_input().split())
    print(runnerScore(arr))
