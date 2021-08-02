
def get_change(m):
    #write your code here
    coins = 0
    while m > 0:
        if(m >= 1 and m < 5):
            m = m - 1
            coins += 1
        if(m >= 5 and m < 10):
            m = m - 5
            coins += 1
        if(m >= 10):
            m = m - 10
            coins += 1
    return coins 

if __name__ == '__main__':
    m = int(input())
    print(get_change(m))


