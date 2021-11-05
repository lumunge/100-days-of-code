#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;



class Solution {
    public:
        bool searchMatrix(vector<vector<int>> &matrix, int target){
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){
                    if(matrix[i][j] == target)
                        return true;
                }
            }
            return false;                   
        }
};

int main(){
    Solution soln;
    vector<vector<int>> mat = {{1, 3, 5, 7},
                               {10, 11, 16, 20},
                               {23, 30, 34, 60}};
    cout << soln.searchMatrix(mat, 3) << endl;
    cout << soln.searchMatrix(mat, 27) << endl;
    return 0;
}
