# DYNAMIC PROGRAMMING

#### Conditions for DP:
     1: Overlapping Subproblems --> Solutions of same subproblems are needed again and again.
     2: Optimal substructure

#### Storing Values for Reuse in DP:
     1: Memoization(Top Down) --> Make a lookup in table before computing solutions
                                  The table is filled on demand.
     2: Tabulation(Bottom up) --> Builds the solution from first and return the last entry from table.
                                  Starting from first entry all entries are filled one by one
