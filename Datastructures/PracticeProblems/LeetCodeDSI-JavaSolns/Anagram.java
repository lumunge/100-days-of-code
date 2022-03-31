//Given two strings s and t, return true is t is an anagram of s otherwise false
//Leetcode 242

import java.util.Arrays;

class Anagram{
    static boolean validAnagram(String s, String t){
        char sTemp[] = s.toCharArray();
        char tTemp[] = t.toCharArray();
        Arrays.sort(sTemp); Arrays.sort(tTemp);
        return (Arrays.equals(sTemp, tTemp));
    }

    public static void main(String[] args){
        String s = "anagram", t = "nagaram";
        System.out.println(validAnagram(s, t));
    }
}
