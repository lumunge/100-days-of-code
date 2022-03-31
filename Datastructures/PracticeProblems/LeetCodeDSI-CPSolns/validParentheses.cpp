#include<iostream>
#include<stack>

using std::stack;
using std::string;
using std::cout;
using std::endl;

/* PROBLEM STATEMENT:
 * Given a string s containing '(', ')', '{', '}', '[', ']', determine if the input string
 * is valid.
 * Open brackets must be closed by the same type of brackets
 * Open brackets must be closed in the correct order
 *
 * Approach:
 * Initialize an empty stack
 * Loop through the string, push opening parenthesis to stack to top of stack,
 * continue with loop.
 * If found matching closing parentheses in the string, pop the stack.
 * Finally if the stack is not empty after the loop, return false, else true.
 */

class Solution {
    public:
        void printStack(stack<char> stack){
            while (!stack.empty()) {
                cout << ' ' << stack.top();
                stack.pop();
            }
        }
        bool isValid(string s){
            stack<char> stack;
            for(int i = 0; i < s.length(); i++){
                if(s[i] == '{' || s[i] == '(' || s[i] == '[')
                    stack.push(s[i]);
                else if(!stack.empty() && stack.top() == '{' && s[i] == '}' || !stack.empty() && stack.top() == '(' && s[i] == ')' || !stack.empty() && stack.top() == '[' && s[i] == ']')
                    stack.pop();
                else
                    return false;
            }
            return stack.empty();
        }
};

int main(){
    Solution soln;
    string s = "()[]{}";
    string s2 = "{]}";
    cout << soln.isValid(s) << endl;
    cout << soln.isValid(s2) << endl;
    return 0;
}
