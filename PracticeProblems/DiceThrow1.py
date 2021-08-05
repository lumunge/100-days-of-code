"""
Combine all posibilities of two die being tosssed
Get their respesctive results and return
"""
from itertools import product

def count_wins(dice1, dice2):
    assert len(dice1) == 6 and len(dice2) == 6
    dice1_wins, dice2_wins = 0, 0
    
    combs = list(product(dice1, dice2))

    for i in combs:
        if(i[0] > i[1]):
            dice1_wins += 1
        elif(i[1] > i[0]):
            dice2_wins += 1

    return (dice1_wins, dice2_wins)

if __name__ == "__main__":
    firstDie = list(map(int, input().split()))[:6]
    secondDie = list(map(int, input().split()))[:6]
    print(count_wins(firstDie, secondDie))

"""
Tests
count_wins([1, 1, 6, 6, 8, 8], [2, 2, 4, 4, 9, 9]) => (16, 20)
count_wins([1, 2, 3, 4, 5, 6], [1, 2, 3, 4, 5, 6]) => (15, 15)
"""
