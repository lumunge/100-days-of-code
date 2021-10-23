def majorityElement(arr):
    index = 0
    count = 1
    for i in range(len(arr)):
        if arr[index] == arr[i]:
            count += 1
        else:
            count -= 1
        if count == 0:
            index = i
            count = 1
    return arr[index]

def checkMajority(arr, candidate):
    count = 0
    for i in range(len(arr)):
        if arr[i] == candidate:
            count += 1
    if count > len(arr) / 2:
        return True
    else:
        return False


def printMajority(arr):
    candidate = majorityElement(arr)
    if checkMajority(arr, candidate) == True:
        return 1
    else:
        return 0



if __name__ == "__main__":
    n = int(input())
    lst = list(map(int, input().split()))

    print(printMajority(lst))





