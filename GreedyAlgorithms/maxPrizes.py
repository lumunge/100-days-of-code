n = int(input())
lst = []
decrement = 1
m = n
while n > 0:
    n = n - decrement
    if(decrement > n or decrement == n):
        break
    lst.append(decrement)
    decrement = decrement + 1

lst.append(m - sum(lst))
newList = []
for i in lst:
    newList.append(str(i))
print(len(lst))
print(" ".join(newList))
