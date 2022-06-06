// Hackerrank - forming a magic square -> https://www.hackerrank.com/challenges/magic-square-forming/

#include<iostream>
#include<vector>
#include<limits.h>

using std::min;
using std::vector;
using std::cout;

class Solution{
    private:
        int getCost(vector<vector<int>> vec, vector<vector<int>> MSQ){ // helper function to get cost
            int cost = 0;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cost += abs(vec[i][j] - MSQ[i][j]);
                }
            }
            return cost;
        }
    public:
        // soln: generate 3x3 magic square, for each find the different costs and evaluate the minimum
        int formingMagicSquare(vector<vector<int>> s){
            vector<vector<vector<int>>> MSQ = { // 3 x 3 magic squares
                {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}}, // single 3 x 3 magic square
                {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
                {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
                {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
                {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
                {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
                {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
                {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
                };
                
            int min_cost = INT_MAX;
            
            for(int i = 0; i < MSQ.size(); i++){
                int curr_cost = getCost(s, MSQ[i]); // get cost
                min_cost = min(min_cost, curr_cost); // evaluate min cost
            }
            
            return min_cost;
        }
};

int main(){
    Solution soln;
    vector<vector<int>> v = {{5, 3, 4}, {1, 5, 8}, {6, 4, 2}};
    cout << soln.formingMagicSquare(v) << "\n";
    return 0;
}

