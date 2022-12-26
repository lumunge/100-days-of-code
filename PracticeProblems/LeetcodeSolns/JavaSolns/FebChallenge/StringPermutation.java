// Leetcode #567 - Permutation in String

import java.util.Arrays;

class StringPermutation{
    private static String sorter(String str){
        char[] charArr = str.toCharArray();
        Arrays.sort(charArr);
        return new String(charArr);
    }
    static boolean checkInclusion(String s1, String s2) {
        int a = s1.length(), b = s2.length();
        if(a > b) return false;
        s1 = sorter(s1);
        for(int i = 0; i <= b - a; i++){
            String sortedWindow = sorter(s2.substring(i, i + a));
            if(s1.equals(sortedWindow)) return true;
        }
        return false;
    }
    public static void main(String[] args){
        System.out.println(checkInclusion("ab", "eidbaooo"));
        System.out.println(checkInclusion("adc", "dcda"));
        System.out.println(checkInclusion("ab", "eidboaoo"));
    }
}
