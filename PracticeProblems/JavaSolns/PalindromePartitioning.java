/*
 * PROBLEM STATEMENT:
 * Given a tring s such that every substring of the partition is a palindrome.
 * Return all possible palindromic partitionings of s.
 *
 * Sample:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 *
 * Approach:(brute force 2^n time)
 * Get all permutations of s and add all palindomes to the reuslt list
 */

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class PalindromePartitioning{
    static boolean isPalindrome(String str, int l, int r){
        while(l < r)
            if(str.charAt(l++) != str.charAt(r--))
                return false;
        return true;
    }

    static void dfs(int start, List<List<String>> result, List<String> currList, String str){
        if(start >= str.length())
            result.add(new ArrayList<String>(currList));
        for(int i = start; i < str.length(); i++){
            if(isPalindrome(str, start, i)){
                currList.add(str.substring(start, i+1));
                dfs(i+1, result, currList, str);
                //backtrack
                currList.remove(currList.size() - 1);
            }
        }
    }

    static List<List<String>> partition(String str){
        List<List<String>> res = new ArrayList<List<String>>();
        dfs(0, res, new ArrayList<String>(), str);
        return res;
    }

    public static void main(String args[]){
        String str = "aab";
        List<List<String>> result = partition(str);
        System.out.println(Arrays.toString(result.toArray()));
    }
}
