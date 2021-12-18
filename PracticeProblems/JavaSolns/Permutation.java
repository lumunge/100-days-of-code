import java.util.ArrayList;

class Permutation {
    static ArrayList<Integer> permutations = new ArrayList<Integer>();
    static void genPermutations(String arr[], int len, int k, int L, int n){
        String num = "";
        for(int i = 0; i < L; i++){
            num += arr[k%len];
            k /= len;
        }
        if(Integer.parseInt(num) <= n){
            permutations.add(Integer.parseInt(num));
            System.out.println(num);
        }
    }
    static void getPermutations(String arr[], int len, int L, int n){
        int count = 0;
        if(arr.length == 1)
            return;
        while(L != 0){
            for(int i = 0; i < Math.pow(len, L); i++){
                genPermutations(arr, len, i, L, n);
            }
            L--;
        }
    }
    static int atMostNGivenDigitSet(String[] digits, int n) {
        int L;
        if(String.valueOf(n).length() > 1)
            L = String.valueOf(n).length()-1;
        else
            L = String.valueOf(n).length();
        int len = digits.length;
        getPermutations(digits, len, L, n);
        return permutations.size();
    }

    public static void main(String[] args){
        String arr[] = {"3", "5"};
        int n = 4;
        String arr1[] = {"1","3","5","7"};
        int n1 = 100;
        String arr2[] = {"1","4","9"};
        int n2 = 1000000000;
        //run one at a time to avoid collisions with the global array list
        //System.out.println(atMostNGivenDigitSet(arr, n)); 
        //System.out.println(atMostNGivenDigitSet(arr1, n1)); 
        System.out.println(atMostNGivenDigitSet(arr2, n2)); 
    }
}
