// Leetcode #1314 - Matrix block sum

#include<iostream>
#include<vector>
#include "rangeSumQuery-304.cpp"

using std::vector;
using std::max; using std::min;
using std::cout; using std::endl;

class MatrixBlockSum{
    public:
        NumMatrix nm;

        vector<vector<int>> blockSum(vector<vector<int>>& mat, int k){
            int r = mat.size(), c = mat[0].size();
            vector<vector<int>> dp = nm.buildMatrix(mat);
            vector<vector<int>> block(r, vector<int>(c));

            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    int r1 = i - k - 1;
                    int c1 = j - k - 1;

                    int r2 = min(r-1, i + k);
                    int c2 = min(c-1, j + k);
                    int d = dp[r2][c2];

                    int a = (r1 >= 0 && c1 >= 0) ? dp[r1][c1] : 0;
                    int b = (r1 >= 0) ? dp[r1][c2] : 0;
                    int c = (c1 >= 0) ? dp[r2][c1] : 0;

                    block[i][j] = (a - b - c) + d;
                }
            }

            return block;
        }
};

int main(){
    MatrixBlockSum mbs;
    NumMatrix nm;
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};

    vector<vector<int>> r = mbs.blockSum(m, 1);
    vector<vector<int>> r1 = mbs.blockSum(m1, 2);
    
    nm.printArr(r);
    cout << endl;
    nm.printArr(r1);

    return 0;
}
