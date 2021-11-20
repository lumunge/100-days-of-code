//Given two strings ransomNote and magazine, return true if ransomNote can be 
//constructued from magazine else false
//Leet code 383

import java.util.HashMap;

class RansomNote{
    static boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> mmap = new HashMap<Character, Integer>();
        int n = ransomNote.length();
        int m = magazine.length();
        if(n > m || n == 0 || m == 0)
            return false;
        for(int i = 0; i < m; i++){
            Integer j = mmap.get(magazine.charAt(i));
            mmap.put(magazine.charAt(i), mmap.getOrDefault(magazine.charAt(i), 0) + 1);
        }
      for(int i = 0; i < n; i++){
          if(!mmap.containsKey(ransomNote.charAt(i)))
              return false;
          mmap.put(ransomNote.charAt(i), mmap.get(ransomNote.charAt(i)) - 1);
          if(mmap.get(ransomNote.charAt(i)) < 0)
              return false;
        }
        return true;
    }

    public static void main(String[] args){
        String ransomNote = "aa";
        String magazine = "ab";
        System.out.println(canConstruct(ransomNote, magazine));
    }
}
