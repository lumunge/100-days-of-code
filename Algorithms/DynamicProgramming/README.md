# DYNAMIC PROGRAMMING

#### Conditions for DP:
     1: Overlapping Subproblems --> Solutions of same subproblems are needed again and again.
     2: Optimal substructure --> If an optimal solution can be constructed from optimal solutions of its subproblems.

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

### Uses of dynamic programming:
#### Finding an optimal solution, the largest/maximum or the smallest/minimum
Coin problem: Given a set of coins and a target, return the minimum number of coins needed to for a solution.
              An example:
                        Coins = {1, 3, 4}
Idea: Get all possible coins using a brute force recursive algorithm
      Use memoization to avoid repeated work

Recursive Formulation:
f(n) - is the function to calculate the minimum number of coins to form target *n*.

n = 10, coins = 3 -> (4 + 3 + 3)
f(0) = 0, f(1) = 1, f(2) = 2, f(3) = 1, f(4) = 1), f(5) = 2
f(6) = 2, f(7) = 2, f(8) = 2, f(9) = 3, f(10) = 3

Each *f(n)* is calculated using smaller values of the function. That is, if coin 3 is selected, we get number of coins
to form *n-3*
The general recursive formula:
```
f(n) = min(f(n - coin1), f(n - coin2), f(n - coin3)) + 1 for n > 0
```

Implementation:
```c++
int minCoins(int n){
    if(n <= 0) return 0;
    vector<int> coins = {1, 3, 4};
    int res = INT_MAX;
    for(int i = 1; i < 3; i++){
        res = min(res, minCoins(n - coins[i])+1);
    }
    return res;
}
```

#### Using memoization to avoid repeated work.
Here, we use an auxilliary array to record already calculated solutions.

*Memoization with recursion*
```c++
int minCoins(int n){
    if(n <= 0) return 0;
    vector<int> dp(200);
    int res = INT_MAX;
    for(int i = 1; i < coins.size(); i++){
        res = min(res, minCoins(n - coins[i])+1);
    }
    dp[n] = res;
    return dp[n];
}
```





* Counting the number of solutions - all possible combinations, solutions, permutations etc.


