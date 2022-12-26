if __name__ == '__main__':
    N = int(input())
    lst = []
    for _ in range(0, N):
        q = input().split()
        if q[0] == "insert":
            lst.insert(int(q[1]), int(q[2]))
        elif q[0] == "print":
            print(lst)
        elif q[0] == "remove":
            lst.remove(int(q[1]))
        elif q[0] == "append":
            lst.append(int(q[1]))
        elif q[0] == "sort":
            lst.sort()
        elif q[0] == "pop":
            lst.pop()
        else:
            lst.reverse()
