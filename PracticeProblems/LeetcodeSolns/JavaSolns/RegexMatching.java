/*
 * PROBLEM STATEMENT:
 * Given a string s and pattern p, support '.' and '*' where;
 * '.' matches any single character
 * '*' matches zero or more of the preceeding chracter
 * Matching should cover the entire string.
 *
 * Approach(bottom up dp)
 * Recurrence relation:
 *          T[i-1][j-1] if str[i] == pattern[j] || pattern[j] == '.'
 *   s  p     
 * T[i][j]  T[i][j-2] for no occurence of value at pattern[j-1]; if pattern[j] == '*'
 *          T[i-1][j-1] if str[i] == pattern[j-1] || pattern[j-1] == '.'; if pattern[j] == '*'
 *
 *
 * Sample:
 * Input: string s = bczdav, pattern p = b*cd.v
 * Output: false;
 * Explanation:
 *              0 1 2 3 4 5 6
 * dp[][] = ["" 0 b * c d . v]
 *          [0  T F T F F F F]
 *          [b  F T T F F F F]
 *          [c  F F F T F F F]
 *          [z  F F F F F F F]
 *          [d        .      ]
 *          [a        .      ]
 *          [v  F F F F F F F]
 * 
 * Input: string s = xaabyc, pattern p = xa*b.c
 * Output: true;
 * Explanation:
 *           "" 0 1 2 3 4 5 6
 *          [     x a * b . c]  
 * dp[][] = ["" T F F F F F F]
 *          [x  F T F T F F F]
 *          [a  F F T T F F F]
 *          [a  F F F T F F F]
 *          [b  F F F F T F F]
 *          [y  F F F F F T F]
 *          [c  F F F F F F T]
 */

import java.util.regex.*;

class RegexMatching{
    //using built-int help
    static boolean regexMatch(String str, String pat){
        Pattern p = Pattern.compile(pat);
        Matcher mat = p.matcher(str);
        return mat.matches();
    }
    
    static boolean regexMatchII(String s, String p) {
        boolean T[][] = new boolean[s.length() + 1][p.length() + 1];
        
        //first cell
        T[0][0] = true;
        
        for(int i = 1; i < T[0].length; i++){
            if(p.charAt(i-1) == '*')
                T[0][i] = T[0][i-2];
        }
        
        for(int i = 1; i < T.length; i++){
            for(int j = 1; j < T[0].length; j++){
                if(p.charAt(j-1) == '.' || p.charAt(j-1) == s.charAt(i-1))
                    T[i][j] = T[i-1][j-1];
                else if(p.charAt(j-1) == '*'){
                    T[i][j] = T[i][j-2];
                    if(p.charAt(j-2) == '.' || p.charAt(j-2) == s.charAt(i-1))
                        T[i][j] = T[i][j] || T[i-1][j];
                }
                else
                    T[i][j] = false;
            }
        }
        //last cell
        return T[s.length()][p.length()];
    }


    public static void main(String[] args){
        System.out.println(regexMatchII("aa", "a"));
        System.out.println(regexMatchII("aa", "a*"));
        System.out.println(regexMatchII("ab", ".*"));
    }
}
