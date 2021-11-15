class MatrixReshape{
    public static int[][] reshape(int[][] mat, int r, int c){
        int or = mat.length;
        int oc = mat[0].length;
        if(r * c != or * oc)
            return mat;
        int[][] newMatrix = new int[r][c];
        for(int i = 0; i < or*oc; i++){
            newMatrix[i/c][i%c] = mat[i/oc][i%oc];
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
        int newMatrix[][] = reshape(matrix, 1, 4);
        printMatrix(matrix);
        System.out.println();
        printMatrix(newMatrix);
    }
}
