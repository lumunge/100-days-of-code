class RichestCustomer{
    static int maxWealth(int[][] accounts){
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < accounts.length; i++){
            int currMax = 0;
            for(int j = 0; j < accounts[i].length; j++)
                currMax += accounts[i][j];
            if(currMax > max) max = currMax;
        }
        return max;
    }

    public static void main(String[] args){
        int acc1[][] = {{1, 2, 3}, {3, 2, 1}};
        int acc2[][] = {{1, 5}, {7, 3}, {3, 5}};
        int acc3[][] = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
        System.out.println(maxWealth(acc1));
        System.out.println(maxWealth(acc2));
        System.out.println(maxWealth(acc3));
    }
}
