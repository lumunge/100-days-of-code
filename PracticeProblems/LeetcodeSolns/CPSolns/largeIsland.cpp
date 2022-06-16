#include<iostream>
#include<set>
#include<vector>

using std::vector;
using std::set;
using std::max;
using std::cout;
using std::endl;

/* 
 * PROBLEM STATEMENT:
 * Given a nXn grid, change at most 0 to 1 to find the largest island and return it.
 *
 * Sample:
 * Input: grid = [[1, 0], [0, 1]];
 * Output: 3
 *
 * Explanation: 0 changes to 1.
 *
 * Input: grid = [[1, 1], [1, 0]];
 * Output: 4
 *
 * Explanation: change the 1 zero to obtain the largest island.
 *
 * Naive Approach:
 * Change all zeros to 1 and dfs the grid to estimate the largest island and return
 */

class LargestIsland{
    private:
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int dfs(vector<vector<int>> &grid, int r, int c, int index){
            if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1)
                return 0;
            int result = 1;
            grid[r][c] = index;
            for(int i = 0; i < 4; i++){
                int nr = dir[i][0] + r;
                int nc = dir[i][1] + c;
                result += dfs(grid, nr, nc, index);
            }
            return result;
        }
    public:
        int largestIsland(vector<vector<int>> &grid){
            int result = 0;
            int index = 2;
            vector<int> area(2);
            int r = grid.size(), c = grid[0].size();
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(grid[i][j] == 1){
                        area.push_back(dfs(grid, i, j, index));
                        result = max(result, area.back());
                        index++;
                    }
                }
            }
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(grid[i][j] == 0){
                        set<int> ids;
                        for(int k = 0; k < 4; k++){
                            int ni = i + dir[k][0];
                            int nj = j + dir[k][1];
                            if(ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size())
                                continue;
                            if(grid[ni][nj])
                                ids.insert(grid[ni][nj]);
                        }
                        int tmp = 1;
                        set<int>::iterator it = ids.begin();
                        while(it != ids.end()){
                            tmp += area[*it];
                            it++;
                        }
                        result = max(result, tmp);
                    }
                }
            }
            return result;
        }
};

int main(){
    LargestIsland li;
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    vector<vector<int>> grid1 = {{1, 1}, {1, 0}};
    vector<vector<int>> grid2 = {{0}};
    cout << li.largestIsland(grid) << endl; 
    cout << li.largestIsland(grid1) << endl; 
    cout << li.largestIsland(grid2) << endl; 
    return 0;
}


