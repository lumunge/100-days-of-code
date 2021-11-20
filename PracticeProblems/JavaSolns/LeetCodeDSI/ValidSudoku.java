//Determine if a 9X9 sudoku board is valid
//Leetcode 36

import java.util.HashSet;

class ValidSudoku{
    static boolean validateSudoku(char[][] board){
        //validate rows and cols
        for(int i = 0; i < 9; i++){
            HashSet<Character> rows = new HashSet<>();
            HashSet<Character> cols = new HashSet<>();
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && !rows.add(board[i][j]))
                    return false;
                 if(board[j][i] != '.' && !cols.add(board[j][i]))
                    return false;
            }
        }
        //validate boxes
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                HashSet<Character> boxes = new HashSet<>();
                for(int k = i; k < i+3; k++){
                    for(int l = j; l < j+3; l++){
                        if(board[k][l] != '.' && !boxes.add(board[k][l]))
                            return false;
                    }
                }
            }
        }
        return true;
    }

    public static void main(String[] args){
        char board1[][] = {{'5','3','.','.','7','.','.','.','.'},
                           {'6','.','.','1','9','5','.','.','.'},
                           {'.','9','8','.','.','.','.','6','.'},
                           {'8','.','.','.','6','.','.','.','3'},
                           {'4','.','.','8','.','3','.','.','1'},
                           {'7','.','.','.','2','.','.','.','6'},
                           {'.','6','.','.','.','.','2','8','.'},
                           {'.','.','.','4','1','9','.','.','5'},
                           {'.','.','.','.','8','.','.','7','9'}};

        char board2[][]  = {{'8','3','.','.','7','.','.','.','.'},
                            {'6','.','.','1','9','5','.','.','.'},
                            {'.','9','8','.','.','.','.','6','.'},
                            {'8','.','.','.','6','.','.','.','3'},
                            {'4','.','.','8','.','3','.','.','1'},
                            {'7','.','.','.','2','.','.','.','6'},
                            {'.','6','.','.','.','.','2','8','.'},
                            {'.','.','.','4','1','9','.','.','5'},
                            {'.','.','.','.','8','.','.','7','9'}};
        System.out.println(validateSudoku(board1));
        System.out.println(validateSudoku(board2));
    }
}







