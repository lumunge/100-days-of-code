// Leetcode #200 - Number of islands

class Solution {
    private:
        void dfs(vector<vector<char>>& grid, int i, int j, int row, int col){
            if(i < 0 || j < 0 || i > (row - 1) || j > (col - 1) || grid[i][j] != '1') return; // edge cases
            if(grid[i][j] == '1'){ // an island
                grid[i][j] = '0';
                dfs(grid, i-1, j, row, col); // top neighbor
                dfs(grid, i, j+1, row, col); // right
                dfs(grid, i+1, j, row, col); // bottom
                dfs(grid, i, j-1, row, col); // left
            }
        }
    public:
        int numIslands(vector<vector<char>>& grid) {
            int islands = 0;
            int row = grid.size(), col = grid[0].size();
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    if(grid[i][j] == '1'){ // an island
                        grid[i][j] = '0';
                        islands++;
                        dfs(grid, i-1, j, row, col); // top neighbor
                        dfs(grid, i, j+1, row, col); // right
                        dfs(grid, i+1, j, row, col); // bottom
                        dfs(grid, i, j-1, row, col); // left
                    }
                }
            }
            return islands;
        }
};
