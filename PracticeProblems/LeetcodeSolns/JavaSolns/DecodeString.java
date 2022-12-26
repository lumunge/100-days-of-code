/*
 * PROBLEM STATEMENT:
 * Given an encoded string, return its decoded string.
 * The encoding rule is: k[encoded_string], where encodes_string inside square brackets is
 * repeated k time. K is a positive integer.
 *
 * Sample:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 *
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 *
 * Approach:
 * There are 4 cases we encounter while traversing the string s
 * 1: A number
 * 2: A character
 * 3: An opening square bracket
 * 4: A closing square bracket
 * Two stacks, one to store the numbers, another for strings.
 * Push string characters and numbers to respective stacks.
 * When a closing brace is encountered pop the number stack and multiply string k times
 */

import java.util.Stack;

class DecodeString{
    static String multiplyStr(int n, String s){
        String result = "";
        for(int i = 0; i <= n; i++)
            result += s;
        return result;
    }

    static String decode(String s){
        Stack<String> str = new Stack<>();
        Stack<Integer> count = new Stack<>();
        StringBuilder result = new StringBuilder();
        int i = 0;
        while(i < s.length()){
            if(Character.isDigit(s.charAt(i))){
                int n = 0;
                while(Character.isDigit(s.charAt(i))){
                    n = n * 10 + (s.charAt(i) - '0');
                    i++;
                }
                count.push(n);
            }else if(s.charAt(i) == '['){
                str.push(result.toString());
                result = new StringBuilder("");
                i++;
            }else if(s.charAt(i) == ']'){
                StringBuilder temp = new StringBuilder(str.pop());
                int multiplier = count.pop();
                for(int j = 0; j < multiplier; j++)
                    temp.append(result);
                result = temp;
                i++;
            }else{
                result.append(s.charAt(i));
                i++;
            }
        }
        return result.toString();
    }

    public static void main(String[] args){
        String s1 = "3[a]2[bc]";
        String s2 = "3[a2[c]]";
        String s3 = "2[abc]3[cd]ef";
        String s4 = "abc3[cd]xyz";
        System.out.println(decode(s1));
        System.out.println(decode(s2));
        System.out.println(decode(s3));
        System.out.println(decode(s4));
    }
}
