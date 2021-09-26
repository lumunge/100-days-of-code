#include<iostream>
#include<vector>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Image is represented by mXn grid
 * Given intergers sr, sc and newColor
 * Perform 4-directional floodfill on image starting from image[sr][sc];
 *  Sample:
 *  Input: image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}
 *         sr, sc = 1
 *         newColor = 2;
 *  Output: {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}}
 *
 *  Explanation: ==> Convert all neighbours(4-directionally) of 
 *                   image[sr][sc] --> image[1][1] that are same color as image[sr][sc]
 *                   to newColor = 2;
 *
 *              1    1   1          2    2   2
 *              1   [1]  0   -->    2    2   0
 *              1    0   1          2    0   1
 *
 */

class Solution{
    public:
        void printArr(vector<vector<int>>& arr){
            for(int i = 0; i < arr.size(); i++){
                for(int j = 0; j < arr.size(); j++){
                    cout << "idx: " << "[" << i << "][" << j << "]";
                    cout << " = " << arr[i][j] << endl;
                }
            }
        }
        void fill(vector<vector<int>>& image, int r, int c, int oldColor, int newColor){
            if(r < 0 || c < 0 || r >= image.size() || c >= image[0].size() || oldColor != image[r][c])
                return;
            image[r][c] = newColor;
            fill(image, r+1, c, oldColor, newColor);
            fill(image, r-1, c, oldColor, newColor);
            fill(image, r, c+1, oldColor, newColor);
            fill(image, r, c-1, oldColor, newColor);
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
            if(image[sr][sc] == newColor)
                return image;
            fill(image, sr, sc, image[sr][sc], newColor);
            return image;
        }
};

int main(){
    Solution soln;
    vector<vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
    int sr, sc = 0;
    int newColor = 2;
    vector<vector<int>> result = soln.floodFill(image, sr, sc, newColor);
    soln.printArr(result);
    return 0;
}
