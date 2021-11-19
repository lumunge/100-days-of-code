// Given a string s find fitsy non-repeating character and return index otherwise return -1
// Leetcode 387

import java.util.HashMap;

class UniqueChar{
    static int firstUniqueChar(String s){
        HashMap<Character, Integer> hmap = new HashMap<Character, Integer>();
        
        for(int i = 0; i < s.length(); i++){
            Integer j = hmap.get(s.charAt(i));
            hmap.put(s.charAt(i), (j == null) ? 1 : i+1);
        }
        for(int i = 0; i < s.length(); i++){
            if(hmap.get(s.charAt(i)) == 1)
                return i;
        }
        return -1;
    }

    public static void main(String[] args){
        String str = "loveleetcode";
        System.out.println(firstUniqueChar(str));
    }
}
