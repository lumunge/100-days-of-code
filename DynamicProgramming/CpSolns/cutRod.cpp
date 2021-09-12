#include<iostream>
#include<limits.h>

using namespace std;

/*
 * PROBLEM STATEMENT:
 * Rod length n and prices array
 * Max length obtained by cutting rob and selling pieces
 *
 * Sample:
 * length 1 2 3 4 5  6  7  8
 * prices 1 5 8 9 10 17 17 20
 *
 * n = 7 option 1 --> 7 (17)
 *       option 2 --> 6 + 1 (18) (optimal solution)
 */


class CuttingRod{
public:
    int naiveMaxRod(int prices[], int n){
        return this->naiveCutRod(prices, n);
    }
    int dpMaxRod(int prices[], int n){
        return this->dpCutRod(prices, n);
    }
private:
    //Naive recursive solution
    int naiveCutRod(int prices[], int n){
        //base case
        if(n <= 0)
            return 0;

        int maxVal = INT_MIN;
        for(int i = 0; i < n; i++){
            maxVal = max(maxVal, prices[i] + naiveCutRod(prices, n-i-1));
        }
        return maxVal;
    }

    //Dynamic programming solution
    int dpCutRod(int prices[], int n){
        int values[n+1];
        int i, j;
        for(i = 1; i <= n; i++){
            int maxVal = INT_MIN;
            for(j = 0; j < i; j++)
                maxVal = max(maxVal, prices[j] + values[i-j-1]);
            values[i] = maxVal;
        }
        return values[n];
    }
};

int main(){
    CuttingRod soln;
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 7;
    cout << soln.naiveMaxRod(prices, n) << endl;
    cout << soln.dpMaxRod(prices, n) << endl;
    return 0;
}



