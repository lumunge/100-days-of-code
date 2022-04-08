// Leetcode #63 - Unique Paths II

class UniquePathsII{
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        // obstacle in the first cell
        if (obstacleGrid[0][0] == 1) return 0;
        
        int r = obstacleGrid.length, c = obstacleGrid[0].length;
        // add first 
        obstacleGrid[0][0] = 1;
        
        // fill edge column with 1s
        for(int i = 1; i < r; i++){
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i-1][0] == 1) ? 1 : 0;
        }
        // fill edge row with 1s
        for(int j = 1; j < c; j++){
            obstacleGrid[0][j] = (obstacleGrid[0][j] == 0 && obstacleGrid[0][j-1] == 1) ? 1 : 0;
        }
        // storing values
        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                // should not be an obstacle
                if(obstacleGrid[i][j] != 1)
                    // ways of reaching obstacleGrid[i][j]
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                else
                    // cell has obstacle, set to zero
                    obstacleGrid[i][j] = 0;
            }
        }
        return obstacleGrid[r-1][c-1];
    }
}
