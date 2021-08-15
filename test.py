def combo(lst, n):
    if n == 0:
        return [[]]
    combined = []
    for i in range(0, len(lst)):
        m = lst[i]
        rem = lst[i + 1:]
        for p in combo(rem, n-1):
            combined.append([m]+p)
    return combined

def twoSum(nums, target):
    if len(nums) <= 2:
        if sum(nums) == target:
            return [0, 1]
    combined = combo([x for x in nums], 2)
    for i in combined:
        if sum(i) == target:
            res = nums.index(i[0]), nums.index(i[1])
    return ",".join(map(str, res))

if __name__ == "__main__":
    nums = list(map(int, input().split()))
    target = int(input())
    print("["+twoSum(nums, target)+"]")
