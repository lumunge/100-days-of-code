// Given two strings, write a function to check if one is a permutation of the other

import java.util.Arrays;

class Permutation{
    static String sort(String s){
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }

    static boolean isPerm(String s, String t){
        int n = s.length(), m = t.length();
        if(n != m) return false;
        char[] sChar = s.toCharArray();
        char[] tChar = t.toCharArray();
        return (sort(s).equals(sort(t)));
    }
    

    static boolean isPermI(String s, String t){
        int n = s.length(), m = t.length();
        if(n != m) return false;         // must be equal size
        int letters[] = new int[128];    // character set
        char[] sChar = s.toCharArray();
        for(char c : sChar)
           letters[c]++;                // counts
        for(int i = 0; i < m; i++){
           int c = (int) t.charAt(i);
           letters[c]--;
           if(letters[c] < 0) return false;
        }
        return true;
    }

    public static void main(String[] args){
        String s = "dog", t = "God";
        String s1 = "bda", t1 = "abd";
        String s2 = "bzda", t2 = "abd";
        System.out.println(isPerm(s, t));
        System.out.println(isPerm(s1, t1));
        System.out.println(isPerm(s2, t2));
    }
}
