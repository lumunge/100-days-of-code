#include<iostream>
#include<vector>
#include<queue>
#include "./PrintVector.cpp" // printing vector functions
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given an mXn matrix, return distance of nearest 0 for each cell,
 * distance between two adjacent cells is 1;
 *
 * Sample:
 * Input: {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}
 * Output: {{0, 0 0}, {0, 1, 0}. {1, 2, 1}}
 */


class Solution{
    private:
        bool isValid(pair<int, int> cell, int r, int c){
            if(cell.first < 0 || cell.second < 0 || cell.first >= r || cell.second >= c)
                return false;
            return true;
        }
    public:
        vector<vector<int>> matrixDistance(vector<vector<int>>& matrix){
            //rows and columns
            int r = matrix.size();
            int c = matrix[0].size();
            //final distance vector filled with -1 to show unvisited cells
            vector<vector<int>> distance(r, vector<int> (c, -1));
            //queue to store cells ehile visiting neighbors
            queue<pair<int, int>> q;
            //Iterate through matrix
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(matrix[i][j] == 0){ //src node
                        distance[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }
            //moving along neighbors, top, right, down, left
            const int dx[] = {-1, 0, 1, 0};
            const int dy[] = {0, 1, 0, -1};
            while(!q.empty()){
                pair<int, int> node = q.front();
                q.pop();
                for(int t = 0; t < 4; t++){ //no of sides
                    pair<int, int> neighbor = {node.first + dx[t], node.second + dy[t]};
                    //if cell is valid not yet visited
                    if(isValid(neighbor, r, c) && distance[neighbor.first][neighbor.second] == -1){
                        distance[neighbor.first][neighbor.second] = distance[node.first][node.second] + 1;
                        q.push(neighbor);
                    }
                }
            }
            return distance;
        }
};


int main(){
    Solution soln;
    PrintVector print;
    vector<vector<int>> matrix = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> matrixII = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> matrixDistance = soln.matrixDistance(matrix);
    vector<vector<int>> matrixIIDistance = soln.matrixDistance(matrixII);
    print.print2DVector(matrixDistance);
    cout << endl;
    print.print2DVector(matrixIIDistance);
    return 0;
}
