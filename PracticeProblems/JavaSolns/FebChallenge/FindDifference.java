// Leetcode # 389 - find the difference.

import java.util.Arrays;

class FindDifference{
    static char findTheDifference(String s, String t){
        if(s.length() == 0) return t.charAt(0);
        if(t.length() == 0) return t.charAt(0);
        char[] sCharArray = s.toCharArray();
        char[] tCharArray = t.toCharArray();
        Arrays.sort(sCharArray); Arrays.sort(tCharArray);
        for(int i = 0; i < s.length(); i++){
            if(sCharArray[i] != tCharArray[i])
                return tCharArray[i];
        }
        return tCharArray[tCharArray.length-1];
    }

    public static void main(String[] args){
        String s1 = "abcd", t1 = "abcde";
        String s2 = "", t2 = "y";
        System.out.println(findTheDifference(s1, t1));
        System.out.println(findTheDifference(s2, t2));
    }
}
