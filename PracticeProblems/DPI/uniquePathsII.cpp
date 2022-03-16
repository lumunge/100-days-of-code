// Leetcode #63 - Unique paths II

#include<iostream>
#include<vector>

using std::vector;
using std::cout; using std::endl;

class Solution{
    public:
        int paths(vector<vector<int>>& og){
            // if first cell is an obstacle
            if(og[0][0] == 1) return 0;
            // grid size
            int r = og.size(), c = og[0].size();
            
            // first cell not zero, add as path
            og[0][0] = 1;

            // fill edge col with 1s
            for(int i = 1; i < r; i++)
                og[i][0] = (og[i][0] == 0 && og[i-1][0] == 1) ? 1 : 0;
            // fill edge row with 1s
            for(int j = 1; j < c; j++)
                og[0][j] = (og[0][j] == 0 && og[0][j-1] == 1) ? 1 : 0;
            // evaluate paths
            for(int i = 1; i < r; i++){
                for(int j = 1; j < c; j++){
                    // should not be an obstacle
                    if(og[i][j] != 1)
                        og[i][j] = og[i-1][j] + og[i][j-1];
                    else
                        // is an obstacle, make value 0
                        og[i][j] = 0;
                }
            }
            // return last value
            return og[r-1][c-1]; 
        }
};

int main(){
    Solution soln;
    vector<vector<int>> og = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> og1 = {{0, 1}, {0, 0}};
    cout << soln.paths(og) << endl;
    cout << soln.paths(og1) << endl;
    return 0;
}
