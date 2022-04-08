// Leetcode #139 - Word break

import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.Arrays;

class WordBreak {    
    private static boolean helper(Set<String> set, String str, int start){
        int n = str.length();
        Boolean[] dp = new Boolean[n];
        if(n == start) return true;
        for(int i = start; i < n; i++){
            if(set.contains(str.substring(start, i + 1))) // check existence in set
                if(helper(set, str, i+1)) return dp[start] = true; // store in dp
        }
        return dp[start] = false;
    }
    
    public static boolean wordBreak(String s, List<String> wordDict){
        Set<String> set = new HashSet<>();
        for(String str: wordDict)
            set.add(str);
        return helper(set, s, 0);
    }

    // opimization
    public static boolean wordBreakI(String s, List<String> wordDict){
        int n = s.length();
        Boolean[] dp = new Boolean[n + 1];
        Arrays.fill(dp, false);
        
        for(String str : wordDict){
            if(s.startsWith(str))
                dp[str.length()] = true;
        }
        
        for(int i = 0; i < n; i++){
            if(dp[i] == false) continue;
            String curr = s.substring(0, i);
            for(String str : wordDict){
                if(s.startsWith(curr + str))
                    dp[(curr+str).length()] = true;
            }
        }
        
        return dp[n];
    }

    public static void main(String[] args){
        String s = "leetcode"; List<String> d = Arrays.asList("leet", "code");
        String s1 = "applepenapple"; List<String> d1 = Arrays.asList("apple", "pen");
        System.out.println(wordBreak(s, d));
        System.out.println(wordBreak(s1, d1));
        System.out.println(wordBreakI(s, d));
        System.out.println(wordBreakI(s1, d1));
    }
}
