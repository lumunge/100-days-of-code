#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_set;
using std::unordered_map;

/* PROBLEM STATEMENT:
 * Determine if a 9X9 sudoku board is valid, Only filled cells need validation according
 * to the rules.
 * 1. Each row must contain digits 1-9 without repetition.
 * 2. Each column must contain digits 1-9 without repetition. 
 * 3. Each of the 9 3X3 sub-boxes of grid must contain digits 1-9 without repetition.
 * 
 */

class Solution {
    public:
        bool isValidSudoku(vector<vector<string>>& board){
            unordered_map<int, unordered_set<string>> row, col, box;
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    if(board[i][j] != "."){
                        //if row or column value is repeated
                        if(row[i].find(board[i][j]) != row[i].end() || col[j].find(board[i][j]) != col[j].end())
                            return false;
                        //calculate box number
                        int b = (j/3) + 3 * (i/3);
                        //if box numbers are repeated
                        if(box[b].find(board[i][j]) != box[b].end())
                            return false;
                        row[i].insert(board[i][j]);
                        col[j].insert(board[i][j]);
                        box[b].insert(board[i][j]);
                    }
                }
            }
            row.clear(); col.clear(); box.clear();
            return true;
        }
};

int main(){
    Solution soln;
    vector<vector<string>> board1 = {{"5","3",".",".","7",".",".",".","."},
                                  {"6",".",".","1","9","5",".",".","."},
                                  {".","9","8",".",".",".",".","6","."},
                                  {"8",".",".",".","6",".",".",".","3"},
                                  {"4",".",".","8",".","3",".",".","1"},
                                  {"7",".",".",".","2",".",".",".","6"},
                                  {".","6",".",".",".",".","2","8","."},
                                  {".",".",".","4","1","9",".",".","5"},
                                  {".",".",".",".","8",".",".","7","9"}};

    vector<vector<string>> board2  = {{"8","3",".",".","7",".",".",".","."},
                                   {"6",".",".","1","9","5",".",".","."},
                                   {".","9","8",".",".",".",".","6","."},
                                   {"8",".",".",".","6",".",".",".","3"},
                                   {"4",".",".","8",".","3",".",".","1"},
                                   {"7",".",".",".","2",".",".",".","6"},
                                   {".","6",".",".",".",".","2","8","."},
                                   {".",".",".","4","1","9",".",".","5"},
                                   {".",".",".",".","8",".",".","7","9"}};

    cout << soln.isValidSudoku(board1) << endl;
    cout << soln.isValidSudoku(board2) << endl;
    return 0;
}
