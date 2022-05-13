"""https://www.hackerrank.com/challenges/find-a-string/"""

def count_substring(string, sub_str):
    n, m = len(string), len(sub_str)
    if(n < m):
        return 0;
    count = 0
    for i in range(n - m + 1):
        if(string[i : i + m] == sub_str):
            count += 1
    return count

if __name__ == "__main__":
    string = input().strip()
    sub_str = input().strip()
    print(count_substring(string, sub_str))
