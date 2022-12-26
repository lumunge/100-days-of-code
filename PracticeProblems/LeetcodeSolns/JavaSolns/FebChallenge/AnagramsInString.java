// Leetcode 438

import java.util.ArrayList;
import java.util.List;

class AnagramsInString{
    static int[] hash, phash;
    static boolean checker(){
        for(int i = 0; i < 26; i++){
            if(hash[i] != phash[i]) return false;
        }
        return true;
    }
    
    static List<Integer> findAnagrams(String s, String p) {
        int window = p.length();
        int n = s.length();
        List<Integer> res = new ArrayList<>();
        
        if(window > n) return res;
        
        hash = new int[26];
        phash = new int[26];
        
        int l = 0, r = 0;
        
        for(char c : p.toCharArray()) phash[c - 'a']++;
        
        while(r < n){
            char curr = s.charAt(r);
            hash[curr - 'a']++;
            if(r - l + 1 < window) r++;
            else{
                if(checker()) res.add(l);
                hash[s.charAt(l) - 'a']--;
                l++;
                r++;
            }
        }
        return res;
    }

    public static void main(String[] args){
        String s1 = "cbaebabacd", p1 = "abc";
        String s2 = "abab", p2 = "ab";
        System.out.println(findAnagrams(s1, p1));
        System.out.println(findAnagrams(s2, p2));
    }
}
