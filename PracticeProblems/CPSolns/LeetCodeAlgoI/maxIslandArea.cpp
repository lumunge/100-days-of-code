#include<iostream>
#include<vector>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given a mXn matrix grid. An island is agroup of 1s connected 4-directionally
 * Area of island is number of cells with value 1 in the island
 * Return maximum are of an island else return 0;
 */

class Solution{
    public:
        int dfs(vector<vector<int>>& grid, int i, int j){
            int r = grid.size(); //rows
            int c = grid[0].size(); //columns;
            if(i < 0 || j < 0 || i >= r || j >= c || grid[i][j] != 1)
                return 0;
            grid[i][j] = 2;
            return (1 + dfs(grid, i+1, j) + //bottom
                        dfs(grid, i-1, j) + //top
                        dfs(grid, i, j+1) + //right
                        dfs(grid, i, j-1) //left
                   );
        }
        int maxAreaOfIsland(vector<vector<int>>& grid){
            int r = grid.size();
            int c = grid[0].size();
            int result = 0;
            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j)
                    if(grid[i][j] == 1)
                        result = max(result, dfs(grid, i, j));
            }
            return result;
        }
};

int main(){
    Solution soln;
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << soln.maxAreaOfIsland(grid) << endl;
    return 0;
}
