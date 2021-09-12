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
    int bruteMaxRod(int prices[], int n){
        return this->bruteCutRod(prices, n);
    }
    int dpMaxRod(int prices[], int n){
        return this->dpCutRod(prices, n);
    }
private:
    int bruteCutRod(int prices[], int n){
        //base case
        if(n <= 0)
            return 0;

        int maxVal = INT_MIN;
        for(int i = 0; i < n; i++){
            maxVal = max(maxVal, prices[i] + bruteCutRod(prices, n-i-1));
        }
        return maxVal;
    }
    int dpCutRod(int prices[], int n){
        return 0;
    }
};

int main(){
    CuttingRod soln;
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 7;
    cout << soln.bruteMaxRod(prices, n) << endl;
    return 0;
}
