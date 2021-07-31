def maxPairWiseProductModelFast(arr):
    max1 = arr.index(max(arr))
    arr2 = [x for x in range(len(arr)) if x != max1]
    arr3 = [] 
    for i in arr2:
        arr3.append(arr[i])
    return arr[max1] * max(arr3)



if __name__ == '__main__':
    input_n = int(input())
    input_numbers = [int(x) for x in input().split()]
    print(maxPairWiseProductModelFast(input_numbers))

