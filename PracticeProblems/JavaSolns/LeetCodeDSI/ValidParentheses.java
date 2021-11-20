// Given a string s containing characters '(' ')' '[' ']' '{' '}' determine if the string
//  is valid
// Leet code 20

import java.util.Stack;

class ValidParentheses{
    static boolean isValid(String s){
        Stack<Character> stack = new Stack<>();
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '{' || s.charAt(i) == '(' || s.charAt(i) == '[')
                stack.push(s.charAt(i));
            else if(!stack.empty() && stack.peek() == '{' && s.charAt(i) == '}' || !stack.empty() && stack.peek() == '(' && s.charAt(i) == ')' || !stack.empty() && stack.peek() == '[' && s.charAt(i) == ']')
                stack.pop();
            else
                return false;
        }
        return stack.empty();
    }

    public static void main(String[] args){
        String s1 = "()";
        String s2 = "(]";
        System.out.println(isValid(s1));
        System.out.println(isValid(s2));
    }
}
