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
 *
 * DYNAMIC PROGRAMMING APPROACH:
 * Construct a arr[][] to avoid recomputation of same values
 * eg:
 *      weights = {2, 3, 4, 5}
 *      values = {1, 2, 5, 6}
 *      capacity = 8
 *                      weights(w)
 *      arr[i][w] = [0 1 2 3 4 5 6 7 8
 *      v  w         0 0 0 0 0 0 0 0 0
 *      1, 2         1 0 1 1 1 1 1 1 1
 *      2, 3         2 0 1 2 2 3 3 3 3
 *      5, 4         3 0 1 2 5 5 6 7 7
 *      6, 5         4 0 1 2 5 6 6 7 8]
 *
 *                  x4 = 8, 8 only generated in 4th row, therefore include 4 object in bag x4 = 1;
 *                  --> 8 - 6 = 2
 *                  x3 = Is 2 present in 3rd row and 2 is also present in 2nd row, therefore dont include 3rd object: x3 = 0;
 *                  x2 = 2 is in 2nd row but not in 1st row, therefore include 2nd object in bag: x2 = 1;
 *                  --> 2 - 2 = 0
 *                  x1 = Is 0 present in 1st row and also present in 0th row, therefore dont include it: x1 = 0;
 *                  
 *                  Result: x1 x2 x3 x4
 *                          0  1  0  1
 *                          2nd and 4th object to get maximum
 *                          6 + 2 = 8
 */

class Knapsack{
public:
    int maxValue(int values[], int weights[], int capacity, int n){
        return this->bruteKnapsack(values, weights, capacity, n);
    }
    int dpMaxValue(int values[], int weights[], int capacity, int n){
        return this->dpKnapsack(values, weights, capacity, n);
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
    
    int dpKnapsack(int values[], int weights[], int capacity, int n){
        int i, w; //initialize rows and columns for arr table
        vector<vector<int>> arr(n+1, vector<int>(capacity + 1));
        /*
         * arr(3+1, 8+1)
         * ie: i
         * w   0 1 2 3 4 5 6 7 8
         *   0 0 0 0 0 0 0 0 0 0
         *   1 0
         *   2 0
         *   3 0
         */
        //Loop the table filling values; 
        for(i = 0; i <= n; i++){
            for(w = 0; w <= capacity; w++){
                if(i == 0 || w == 0)
                    //first row and column
                    arr[i][w] = 0;
                else if(weights[i-1] <= w)
                    //other rows
                    arr[i][w] = max(values[i-1] + arr[i-1][w - weights[i-1]], arr[i-1][w]);
                else
                    arr[i][w] = arr[i-1][w];
            }
        }
        //arr[3, 8] == 8;
        return arr[n][capacity];
    }
};


int main(){
    Knapsack ks;
    int values []= {1, 2, 5, 6};
    int weights[] = {2, 3, 4, 5};
    int capacity = 8;
    int n = sizeof(values) / sizeof(values[0]);
    cout << ks.maxValue(values, weights, capacity, n) << endl;
    cout << ks.dpMaxValue(values, weights, capacity, n) << endl;
    return 0;
}
