//Leet code 566

import java.util.ArrayList;

class MatrixReshape{
    public static int[][] reshape(int[][] mat, int r, int c){
        int or = mat.length;
        int oc = mat[0].length;
        //if rows and columns are equal
        if(r * c != or * oc)
            return mat;
        //fill new matrix with elements from old matrix
        int[][] newMatrix = new int[r][c];
        for(int i = 0; i < or*oc; i++){
            newMatrix[i/c][i%c] = mat[i/oc][i%oc];
        }
        return newMatrix;
    }

    public static int[][] reshapeII(int[][] mat, int r, int c){
        int or = mat.length, oc = mat[0].length;
        int l = or * oc;
        
        //if rows and columns dont match
        if(or * oc != r*c)
            return mat;
        
        //fill new list with old matrix elements
        ArrayList<Integer> temp = new ArrayList<Integer>();;
        for(int i = 0; i < or; i++){
            for(int j = 0; j < oc; j++){
                temp.add(mat[i][j]);
            }
        }
        //fill new matrix with list elements
        int k = 0;
        int[][] newMatrix = new int[r][c];
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                newMatrix[i][j] = temp.get(k);
                k++;
            }
        }
        return newMatrix;
    }

    public static void printMatrix(int[][] matrix){
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j <  matrix[0].length; j++){
                System.out.print(matrix[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String args[]){
        int matrix[][] = {{1, 2}, {3, 4}};
        //int newMatrix[][] = reshape(matrix, 1, 4);
        int newMatrix[][] = reshapeII(matrix, 1, 4);
        printMatrix(matrix);
        System.out.println();
        printMatrix(newMatrix);
    }
}
