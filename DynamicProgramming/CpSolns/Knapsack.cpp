#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

/* PROBLEM STATEMENT:
 * Given weights and their values, place these items in knapsack of
 * specified capacity such that you obtain the maximum value.
 *
 * BRUTE FORCE APPROACH:
 * Consider all subsets of items an calculate total weights,
 * Then pick the subset with maximum value
 *
 * OPTIMAL SUBSTRUCTURE -> Optimal soln to be constructed from optimal solns to subproblems
 *                      -> Two cases for every item
 *                      1: Either it is included in final soln.
 *                      2: Or it is excluded.
 *
 * Case 1: Maximum value from n-1 items and capacity(nth item excluded) --> ie: weight > capacity
 *         Knapsack(values, weights, capacity, n-1)
 * Case 2: Value of nth item + Maximum value from n-1 items, capacity - weight of nth item.(nth item included)
 *         values[n-1] + Knapsack(values[n-1], weights, capacity - weights[n-1], n-1)
 *
 * Result = Maximum(case1, case2);
 */

class Knapsack{
public:
    int maxValue(int values[], int weights[], int capacity, int n){
        return this->bruteKnapsack(values, weights, capacity, n);
    }
private:
    int max(int a, int b){
        return (a > b) ? a : b;
    }

    int bruteKnapsack(int values[], int weights[], int capacity, int n){
        //Base case
        if(n == 0 || capacity == 0){
            return 0;
        }
        //If weight is greater than capacity
        if(weights[n-1] > capacity)
            return bruteKnapsack(values, weights, capacity, n-1);
        //Else return max (case1, case2)
        else
            return max(bruteKnapsack(values, weights, capacity, n-1), values[n-1] + bruteKnapsack(values, weights, capacity - weights[n-1], n-1)); 
    }

};


int main(){
    Knapsack ks;
    int values []= {160, 100, 120};
    int weights[] = {10, 20, 30};
    int n = sizeof(values) / sizeof(values[0]);
    int capacity = 50;
    cout << ks.maxValue(values, weights, capacity, n) << endl;
    return 0;
}
