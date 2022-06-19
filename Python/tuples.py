if __name__ == '__main__':
    tup = ()
    n = int(input())
    integer_list = map(int, input().split())
    for i in integer_list:
        tup += (i, )
    print(hash(tup))
