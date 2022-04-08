// Leetcode #1014 - Best sightseeing pair

class BestSightPair{
    static int maxScore(int[] values){
        int n = values.length;
        int maxSc = Integer.MIN_VALUE, curr = values[0];
        for(int i = 1; i < n; i++){
            curr--;
            maxSc = Math.max(maxSc, curr + values[i]);
            if(values[i] > curr) curr = values[i];
        }
        return maxSc;
    }

    public static void main(String[] args){
        int[] v = {8, 1, 5, 2, 6};
        int[] v1 = {1, 2};
        System.out.println(maxScore(v));
        System.out.println(maxScore(v1));
    }
}
