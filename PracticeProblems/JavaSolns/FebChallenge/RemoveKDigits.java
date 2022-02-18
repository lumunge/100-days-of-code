// Leetcode #402 - Remove K digits

import java.util.Stack;

class RemoveKDigits{
    static String removeDigits(String num, int k){
        Stack<Character> stack = new Stack();
        
        for(char c : num.toCharArray()){
            while(!stack.isEmpty() && k > 0 && stack.peek() > c){
                stack.pop();
                k--;
            }
            stack.push(c);
        }
        
        while(!stack.isEmpty() && k > 0){
            stack.pop();
            k--;
        }
        
        StringBuilder str = new StringBuilder();
        while(!stack.isEmpty())
            str.append(stack.pop());

        str.reverse();
        
        while(str.length() > 1 && str.charAt(0) == '0')
            str.deleteCharAt(0);
        
        return str.length() > 0 ? str.toString() : "0";
    }
}
