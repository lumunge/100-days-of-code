def isGreaterOrEqual(a, b):
    if(str(a) + str(b) > str(b) + str(a)):
        return True
    else:
        return False

def largestNum(digits):
    answer = ""
    while len(digits) != 0:
        maxDigit = float("-inf")
        for digit in digits:
            if isGreaterOrEqual(digit, maxDigit):
                maxDigit = digit
        answer = answer + str(maxDigit)
        digits.remove(maxDigit)
    return answer


if __name__ == "__main__":
    n = int(input())
    digits = list(map(int, input().split(' ')[:n]))
    print(largestNum(digits))



