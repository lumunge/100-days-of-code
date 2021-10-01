#include<iostream>
#include<queue>

using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given an mXn grid, each cell can have:
 *      0: empty cell
 *      1: fresh orange
 *      2: rotten orange;
 * Every minute any fresh orange that is 4-directionally adjacent to rotten orange
 * rots.
 * Return minimum number of minutes that must elapse until no cell has fresh orange.
 * else return -1;
 *
 * Sample:
 * Input: grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
 * Output: 4;
 */

class Solution{
    public:
        int rottingOranges(vector<vector<int>>& grid){
            //pair to track grid coordinates
            queue<pair<int, int>> rotten;
            //fresh oranges
            int fresh = 0;
            //time taken to rot
            int t = 0;
            //rows and columns
            int r = grid.size();
            int c = grid[0].size();

            //Getting number of fresh oranges & pushing rotten oranges
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(grid[i][j] == 2) //push rotten oranges to queue
                        rotten.push({i, j});
                    else if(grid[i][j] == 1) //count number of fresh oranges
                        fresh++;
                }
            }
            while(!rotten.empty()){
                int n = rotten.size();
                for(int i = 0; i < n; i++){
                    int x = rotten.front().first;
                    int y = rotten.front().second;
                    rotten.pop();
                    if(x > 0 && grid[x-1][y] == 1){ //rot left neighbour
                        grid[x-1][y] = 2;
                        fresh--;
                        rotten.push({x-1, y});
                    }
                    if(y > 0 && grid[x][y-1] == 1){ //rot top
                        grid[x][y-1] = 2;
                        fresh--;
                        rotten.push({x, y-1});
                    }
                    if(x < r-1 && grid[x+1][y] == 1){ //rot right
                        grid[x+1][y] = 2;
                        fresh--;
                        rotten.push({x+1,y});
                    }
                    if(y < c-1 && grid[x][y+1] == 1){ //rot bottom
                        grid[x][y+1] = 2;
                        fresh--;
                        rotten.push({x,y+1});
                    }
                }
                if(!rotten.empty())
                    t++;
            }
            //if there are not any fresh oranges left, return time taken
            return (fresh == 0) ? t : -1;
        }
};

int main(){
    Solution soln;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    //return -1 --> orange @ grid[2][0] wont rot, not near rotten orange
    vector<vector<int>> grid2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << soln.rottingOranges(grid2) << endl;
    return 0;
}
