# DYNAMIC PROGRAMMING

#### Conditions for DP:
     1: Overlapping Subproblems --> Solutions of same subproblems are needed again and again.
     2: Optimal substructure

#### Storing Values for Reuse in DP:
     1: Memoization(Top Down) --> Make a lookup in table before computing solutions
                                  The table is filled on demand.
     2: Tabulation(Bottom up) --> Builds the solution from first and return the last entry from table.
                                  Starting from first entry all entries are filled one by one


### Example:
    Get ugly numbers:
    Ugly numbers -> numbers whose primes factors are 2, 3 or 5;
    2 -> 2;                 
    3 -> 3;                 USING DP:
    4 -> 2, 2;                  1: Break priblem to smaller subproblems
    5 -> 5;                         create instances of mulitple of the 3 numbers ie
    6 -> 2, 3;                          2 -> 1*2, 2*2, 3*2, 4*2, 5*2
    8 -> 2, 2, 2                        3 -> 1*3, 2*3, 3*3
    9 -> 3, 3                           5 -> 1*5, 2*5
    10 -> 2, 5                      All these will have to be ugly numbers
                                2: i = 2, 4, 6, 8, 10
                                   j = 3, 6, 9
                                   k = 5, 10
                                3: Combine results from subproblems to solve larger problem
                                   Iterations:
                                            1: min(2, 3, 5) ->> 2, i++
                                            2: min(4, 3, 5) ->> 3, j++
                                            3: min(4, 6, 5) ->> 4, i++
                                            4: min(6, 6, 5) ->> 5, j++
                                            5: min(6, 6, 10) ->> 6, i++, j++
                                            6: min(8, 9, 10) ->> 8, i++;


