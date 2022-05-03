# Hackerrank default arguments -> https://www.hackerrank.com/challenges/default-arguments/

class EvenStream(object):
    def __init__(self):
        self.current = 0

    def getNext(self):
        val = self.current
        self.current += 2
        return val

class OddStream(object):
    def __init__(self):
        self.current = 1

    def getNext(self):
        val = self.current
        self.current += 2
        return val

def printFromStream(n, stream=EvenStream()):
    stream.__init__()
    for _ in range(n):
        print(stream.getNext())


queries = int(input())
for _ in range(queries):
    streamName, n = input().split()
    n = int(n)
    if streamName == "even":
        printFromStream(n)
    else:
        printFromStream(n, OddStream())

