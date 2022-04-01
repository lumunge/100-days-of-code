// Leetcode #304 - Range sum query 2D - Immutable

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

class NumMatrix {
    private:
        int dp[201][201];
    public:
        NumMatrix(vector<vector<int>>& matrix) {
            int r = matrix.size(), c = matrix[0].size();

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
        }
        // query
        int sumRegion(int r1, int c1, int r2, int c2) {
            if(r1 == 0 && c1 != 0){
                return dp[r2][c2] - dp[r2][c1-1];
            }else if(r1 != 0 && c1 == 0){
                return dp[r2][c2] - dp[r1-1][c2];
            }else if(r1 == 0 && c1 == 0){
                return dp[r2][c2];
            }else{
                return dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1-1][c1-1];
            }
        }

    void printArr(vector<vector<int>> vec){
        int r = vec.size(), c = vec[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << vec[i][j] << " ";
    
            cout << endl;
        }
    }
};
/*
int main(){
    NumMatrix nm;
    vector<vector<int>> m = {{3,0,1,4,2},
                             {5,6,3,2,1},
                             {1,2,0,1,5}
                             {4,1,0,1,7},
                             {1,0,3,0,5}}
    vector<int> mq1 = {2,1,4,3}, mq2 = {1,1,2,2}, mq3 = {1,2,2,4};
    vector<vector<int>> m1 = {{-4,-5}};
    vector<int> m1q1 = {0,0,0,0}, m1q2 = {0,0,0,1}, m1q3 = {0,1,0,1};
    vector<vector<int>> m2 = {{8,-4,5},
                              {-1,4,4},
                              {-2,3,1},
                              {-4,4,3}};
    vector<int> m2q1 = {0,1,0,2}, m2q2 = {1,1,1,2}, m2q3 = {0,1,0,2};

    vector<vector<int>> m3 = {{7,7,0},
                              {-4,-7,7},
                              {-4,0,-2},
                              {-8,-5,6}};
    vector<int> m3q1 = {1,0,2,2}, m3q2 = {3,2,3,2}, m3q3 = {2,1,2,2}, m3q4 = {0,2,2,2}, m3q5 = {3,2,3,2};


    return 0;
}
*/
    
