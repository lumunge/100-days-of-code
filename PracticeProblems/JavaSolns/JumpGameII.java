//Leet code 45

class JumpGameII {
    private static Integer[] store;

    private static int helper(int[] A, int start) {
        if (start >= A.length - 1)
            return 0;
        if (store[start] != null)
            return store[start];

        int minJump = Integer.MAX_VALUE;
        for (int i = start + 1; i <= start + A[start]; i++)
            minJump = Math.min(minJump, 1 + helper(A, i));

        return store[start] = minJump;
    }

    public static int jump(int[] A) {
        store = new Integer[A.length];
        return helper(A, 0);
    }

    public static void main(String args[]){
        int[] arr = {2, 3, 1, 1, 4};
        System.out.println(jump(arr));
    }
}
