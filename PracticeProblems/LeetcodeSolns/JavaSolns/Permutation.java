/*
 * PROBLEM STATEMENT:
 * Given an array of digits sorted increasingly. Return the number of all positive integer
 * permutations of the digits that are less than or equal to n.
 * less than of equal to n.
 *
 * Sample:
 * Input: ["1", "3", "5", "7"], n = 100
 * Output: 20
 * Explanation: 1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
 *
 * Approach:
 * Naive:
 * Generate all permutations less than n and store all permutations less than n.
 * Return the size of the arraylist which is also the count.
 *
 * Optimal Approach(dp)
 * Maintain a dp array of number of digits given
 */

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

    //Optimized Solution
    static int atMostNGivenDigitSetII(String[] digits, int n){
        String L = String.valueOf(n);
        int len = L.length();
        int dlen = digits.length;
        int dp[] = new int[len+1];
        dp[len] = 1;
        for(int i = len-1; i >= 0; i--){
            int li = L.charAt(i) - '0';
            for(String s : digits){
                if(Integer.valueOf(s) < li){
                    dp[i] += Math.pow(dlen, len-i-1);
                else if(Integer.valueOf(s) == li)
                    dp[i] = dp[i] + dp[i+1];
            }
        }
        for(int i = 1; i < len; i++)
            dp[0] += Math.pow(dlen, i);
        return dp[0];
    }



    public static void main(String[] args){
        String arr[] = {"3", "5"};
        int n = 4;
        String arr1[] = {"1","3","5","7"};
        int n1 = 100;
        String arr2[] = {"1","4","9"};
        int n2 = 1000000000;
        //System.out.println(atMostNGivenDigitSetII(arr, n)); 
        System.out.println(atMostNGivenDigitSetII(arr1, n1)); 
        //System.out.println(atMostNGivenDigitSetII(arr2, n2)); 
    }
}
