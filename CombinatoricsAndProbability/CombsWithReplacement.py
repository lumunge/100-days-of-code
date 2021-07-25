# Salads problem
"""
Tomates, pepper, lettuce, 
Salad of 4 units
How many different salads
"""

from itertools import combinations_with_replacement

salads = []

for i in combinations_with_replacement("TBL", 4):
    salads.append(i)

print(len(salads))




