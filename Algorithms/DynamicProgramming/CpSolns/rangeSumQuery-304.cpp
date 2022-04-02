// Leetcode #304 - Range sum query 2D - Immutable

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

class NumMatrix{
    public:
        vector<vector<int>> buildMatrix(vector<vector<int>>& matrix){
            vector<vector<int>> dp(201, vector<int>(201));
            int r = matrix.size(), c = matrix[0].size();
            // set first value
            dp[0][0] = matrix[0][0];
            // fill first column
            for(int i = 1; i < r; i++){
                dp[i][0] = dp[i-1][0] + matrix[i][0];
            }
            // fill first row
            for(int i = 1; i < c; i++)
                dp[0][i] = dp[0][i-1] + matrix[0][i];    

            // fill middle
            for(int i = 1; i < r; i++){
                for(int j = 1; j < c; j++){
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1] + matrix[i][j]) - dp[i-1][j-1];
                }
            }
            // filled dp table
            return dp;
        }
        // query
        int sumRegion(vector<vector<int>> dp, int r1, int c1, int r2, int c2) {
            if(r1 == 0 && c1 != 0){ // starting row equal to zero
                return dp[r2][c2] - dp[r2][c1-1];
            }else if(r1 != 0 && c1 == 0){ // starting column equal to zero
                return dp[r2][c2] - dp[r1-1][c2];
            }else if(r1 == 0 && c1 == 0){ // starting row and starting column are zero
                return dp[r2][c2];
            }else{ // both not equal to zero
                return dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1-1][c1-1];
            }
        }
        // print dp
        void printArr(vector<vector<int>> vec){
            int r = vec.size(), c = vec[0].size();
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    cout << vec[i][j] << " ";
                }
                cout << endl;
            }
        }
};
/*
int main(){
    NumMatrix nm;
    ///////////////////////////////////////////////////
    vector<vector<int>> m = {{3,0,1,4,2},
                              {5,6,3,2,1},
                              {1,2,0,1,5},
                              {4,1,0,1,7},
                              {1,0,3,0,5}};
    vector<vector<int>> m1 = {{8,-4,5},
                              {-1,4,4},
                              {-2,3,1},
                              {-4,4,3}};
    vector<vector<int>> m2 = {{7,7,0},
                              {-4,-7,7},
                              {-4,0,-2},
                              {-8,-5,6}};
    vector<vector<int>> m3 = {{-4,-5}};
    ///////////////////////////////////////////////////
    vector<vector<int>> dp = nm.buildMatrix(m);
    vector<vector<int>> dp1 = nm.buildMatrix(m1);
    vector<vector<int>> dp2 = nm.buildMatrix(m2);
    vector<vector<int>> dp3 = nm.buildMatrix(m3);

    cout << nm.sumRegion(dp, 2, 1, 4, 3) << endl;
    cout << nm.sumRegion(dp, 1, 1, 2, 2) << endl;
    cout << nm.sumRegion(dp, 1, 2, 2, 4) << endl;

    cout << nm.sumRegion(dp1, 0, 1, 0, 2) << endl;
    cout << nm.sumRegion(dp1, 1, 1, 1, 2) << endl;
    cout << nm.sumRegion(dp1, 0, 1, 0, 2) << endl;

    cout << nm.sumRegion(dp2, 0, 0, 0, 0) << endl;
    cout << nm.sumRegion(dp2, 0, 0, 0, 1) << endl;
    cout << nm.sumRegion(dp2, 0, 1, 0, 1) << endl;

    cout << nm.sumRegion(dp3, 1, 0, 2, 2) << endl;
    cout << nm.sumRegion(dp3, 2, 1, 2, 2) << endl;
    cout << nm.sumRegion(dp3, 0, 2, 2, 2) << endl;
    cout << nm.sumRegion(dp3, 3, 2, 3, 2) << endl;
    
    return 0;
}*/
    
