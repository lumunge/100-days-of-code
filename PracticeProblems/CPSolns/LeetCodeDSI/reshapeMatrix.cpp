#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

/*
 * PROBLEM STATEMENT:
 * Given a m x n matrix and two integers representing number of rows and columns r and c
 * reshape the matrix according to r x c with the original elements from original matrix.
 *
 * Sample:
 * Input: mat = [[1, 2], [3, 4]], r = 1 c = 4
 * Output: [[1, 2, 3, 4]];
 *
 * Input: mat = [[1, 2], [3, 4]], r = 2 c = 4
 * Output: [[1, 2], [3, 4]]
 *
 * Approach: time O(n*m), space O(n*m)
 * Check whether the input rows and columns match the matrix's rows and columns
 * Create a temporary vector to hold all the elements in the input matrix
 * Create a new matrix and insert the elements in correspondence to the inputs r and c.
 * Return the new matrix
 */


class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c){
            int oldRows = mat.size();
            int oldCols = mat[0].size();

            if(oldRows * oldCols != r * c)
                return mat;

            vector<int> temp;
            for(int i = 0; i < oldRows; i++){
                for(int j = 0; j < oldCols; j++){
                    temp.push_back(mat[i][j]);
                }
            }

            vector<vector<int>> result(r);
            int k = 0;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    result[i].push_back(temp[k]);
                    k++;
                }
            }

            return result;
        }

        void printMatrix(vector<vector<int>> mat){
            for(int i = 0; i < mat.size(); i++){
                for(int j = 0; j < mat[0].size(); j++){
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    Solution soln;
    vector<vector<int>> mat = {{1, 2}, {3, 4}};
    vector<vector<int>> result = soln.matrixReshape(mat, 1, 4);
    soln.printMatrix(mat);
    cout << endl;
    soln.printMatrix(result);
    return 0;
}







