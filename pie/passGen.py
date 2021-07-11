import random

def shuffle(string):
    temp = list(string)
    random.shuffle(temp)
    return ''.join(temp)

#Generating random now
upperOne = chr(random.randint(65, 90))
upperTwo = chr(random.randint(65, 90))
lowerOne = chr(random.randint(97, 122))
lowerTwo = chr(random.randint(97, 122))
punctOne = chr(random.randint(32, 152))
punctTwo = chr(random.randint(32, 152))
digitOne = chr(random.randint(48, 57))
digitTwo = chr(random.randint(48, 58))

password = upperOne + upperTwo + lowerOne + lowerTwo + punctOne + punctTwo + digitOne + digitTwo

password = shuffle(password)
print("Your secure password is ", password)
