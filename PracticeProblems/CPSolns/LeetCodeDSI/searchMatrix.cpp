#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

/* PROBLEM STATEMENT:
 * Write an efficient algorithmthat searches for value in mXn matrix.
 * The preoperties of the matrix are as follows;
 *  -> Integers in each row are sorted from left to right
 *  -> First integer in each row is greater then last integer in previous row
 *
 *  Naive Approach: O(n*m) time
 *  Use tow loops to loop through the matrix, If target is found, return true else false
 *
 *  Optimized Approach: O(logn) time
 *  Use binary search row by row in the matrix, if element is found return true else false
 */

class Solution {
    public:
        //using two loops
        bool searchMatrixI(vector<vector<int>> &matrix, int target){
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){
                    if(matrix[i][j] == target)
                        return true;
                }
            }
            return false;                   
        }

        //using binary search
        bool searchMatrixII(vector<vector<int>> &matrix, int target){
            int i = matrix.size(), j = matrix[0].size();
            int l = 0, r = (i*j) - 1;
            while(l <= r){
                int mid = (l+r) / 2;
                if(matrix[mid / j][mid % j] == target)
                    return true;
                else if(matrix[mid / j][mid % j] > target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            return false;
        }
};

int main(){
    Solution soln;
    vector<vector<int>> mat = {{1, 3, 5, 7},
                               {10, 11, 16, 20},
                               {23, 30, 34, 60}};
    cout << soln.searchMatrixII(mat, 3) << endl;
    cout << soln.searchMatrixII(mat, 27) << endl;
    return 0;
}
