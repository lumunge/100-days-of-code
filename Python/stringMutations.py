# string mutations

def mutate_string(string, position, character):
    res = string[:position] + character + string[position+1:]
    # res = list(string)
    # res[position] = character
    return ''.join(res)

if __name__ == '__main__':
    s = input()
    i, c = input().split()
    s_new = mutate_string(s, int(i), c)
    print(s_new)
