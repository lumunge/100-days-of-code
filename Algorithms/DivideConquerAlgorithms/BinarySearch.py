def binary_search(arr, n):
    low, mid = 0, 0
    high = len(arr) - 1
    
    while(low <= high):
        mid = (high + low) // 2
        if(arr[mid] < n):
            low = mid + 1
        elif(arr[mid] > n):
            high = mid - 1
        else:
            return mid
    return -1


if __name__ == "__main__":
    nums = list(map(int, input().split()))[1:]
    searchArr = list(map(int, input().split()))[1:]
    res = []
    for i in searchArr:
        res.append(str(binary_search(nums, i)))
    print(" ".join(res)) 


"""
list1 = [2, 3, 4, 10, 40]
print(binary_search(list1, 40))
"""



