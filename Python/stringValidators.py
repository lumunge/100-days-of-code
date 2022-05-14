# https://www.hackerrank.com/challenges/string-validators/

def alnum(s):
    for i in range(len(s)):
        if(s[i].isalnum()):
            return True;
            break;
    return False;
        
def alpha(s):
    for i in range(len(s)):
        if(s[i].isalpha()):
            return True;
            break;
    return False;

def digit(s):
    for i in range(len(s)):
        if(s[i].isdigit()):
            return True;
            break;
    return False;

def lower(s):
    for i in range(len(s)):
        if(s[i].islower()):
            return True;
            break;
    return False; 
     
def upper(s):
    for i in range(len(s)):
        if(s[i].isupper()):
            return True;
            break;
    return False;
    
if __name__ == '__main__':
    s = input()
    print(alnum(s))
    print(alpha(s))
    print(digit(s))
    print(lower(s))
    print(upper(s))
