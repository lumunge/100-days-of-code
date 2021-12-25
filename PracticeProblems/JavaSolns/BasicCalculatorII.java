/* 
 * PROBLEM STATEMENT:
 * Given a string s which represents an expression, evaluate it an return value.
 *
 * Sample:
 * Input: s = "3+2*2"
 * Output: 7
 * Input: s = " 3/2 "
 * Output: 1
 *
 * Approach:(stack) O(n) space time
 * For addition and subtraction push without popping, that is
 * if current value is a positive value, push it to stack
 * if it is a negative value push -value to stack
 * For multiplication and division, pop top element of stack, evaluate and push result
 * that is, if a * is encountered, pop the stack and push the result
 *          result = next value * popped element, to stack
 * if a / is encountered, pop the stack and push the result
 *          result = nextvalue / popped element, to stack
 * Finally add all elements in the stack and return result.
 *
 * Approach:(temporary value)
 * Keep track of evaluated value thus so far using temp variable,
 * Traverse the string, if the current character is a digit, assign it to current variable
 * curr.
 * Otherwise if the character is an operator(+ or -) add or subtract it to or from temp 
 * variable.
 * If the character is an operator(* or /) get the previously stored curr and multiply it 
 * or divide by the temporary variable stored.
 * Finally add temp and result to obtain the result.
 */

import java.util.Stack;

class BasicCalculator{
    //using stack
    public static int calculateI(String s){
        if(s.length() == 0) return 0;
        Stack<Integer> stack = new Stack<>();
        //remove white spaces
        String str = s.replaceAll("\\s", "");
        int l = str.length();
        int result = 0, curr = 0;
        char op = '+';
        for(int i = 0; i < l; ++i){
            //check if character is a digit
            if(Character.isDigit(str.charAt(i))){
                //convert to int
                curr = (curr * 10) + (str.charAt(i) - '0');
            }
            //not a digit and for evaluation by getting the previous and next character
            if(!Character.isDigit(str.charAt(i)) || i == l-1){
               if(op == '+') stack.push(curr);
               else if(op == '-') stack.push(-curr);
               else if(op == '*') stack.push(stack.pop() * curr);
               else if(op == '/') stack.push(stack.pop() / curr);
               //for evaluation
               op = str.charAt(i);
               curr = 0;
            }
        }
        //Add values from stack
        while(!stack.isEmpty()){
            result += stack.pop();
        }
        return result;
    }
    
    //using temp variable
    //public static int calculateII(String s){
    //}

    public static void main(String args[]){
        String str1 = "3+2*2";
        String str2 = " 3/2 ";
        String str3 = " 3+5 / 2 ";
        System.out.println(calculateI(str1));
        System.out.println(calculateI(str2));
        System.out.println(calculateI(str3));
    }
}

