// Search a 2D matrix
// Leetcode 74

class SearchMatrix{
    static boolean search(int[][] matrix, int target){
        int i = matrix.length, j = matrix[0].length;
        int l = 0, r = (i*j) - 1;
        while(l <= r){
            int mid = (l+r) / 2;
            if(matrix[mid / j][mid % j] == target)
                return true;
            else if(matrix[mid / j][mid % j] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }

    public static void main(String[] args){
        int matrix[][] = {{1, 3, 5, 7},
                          {10, 11, 16, 20},
                          {23, 30, 34, 60}};
        System.out.println(search(matrix, 11));
        System.out.println(search(matrix, 111));
    }
}
