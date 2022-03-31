#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

/* 
 * PROBLEM STATEMENT:
 * Given an integer n, return the first n rows of a pascals triangle.
 *
 *      1
 *    1    1
 *   1   2   1
 *  1  3   3   1
 * 1  4  6   4   1
 *
 * Sample:
 * Input: n = 5;
 * Output: {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}}
 *
 * Approach:
 * Since the pascals triangle numbers are a sum of the two numbers above current index(12 - 16)
 * Create a row with extra zeros both at the front and at the back. (35, 36, 37)
 * To get a value, add the numbers above an index in a row and push row to final matrix 
 * as shown on line 38.
 * Return the matrix.
 */

class Solution {
    public:
        vector<vector<int>> generate(int numRows){
            vector<vector<int>> res;
            res.push_back({1});
            for(int i = 0; i < numRows - 1; i++){
                vector<int> temp = res[res.size() - 1];
                temp.insert(temp.begin(), {0});
                temp.push_back({0});
                vector<int> nextRow;
                vector<int> lastElem = res[res.size() - 1];
                for(int j = 0; j < lastElem.size()+1; j++){
                    nextRow.push_back(temp[j] + temp[j+1]);
                }
                res.push_back(nextRow);
            }
            return res;
        }

        void printVec(vector<vector<int>> arr){
            for(int i = 0; i < arr.size(); i++){
                for(int j = 0; j < arr[i].size(); j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    Solution soln;
    int n;
    cout << "Enter number ", cin >> n;
    vector<vector<int>> pascalsTri = soln.generate(n);
    soln.printVec(pascalsTri);
    return 0;
}
