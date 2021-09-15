#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Implementing a feature for text editor to find error in the usage of brackets in code
 *
 * Sample Input:
 * Input: []
 * Output: Success
 * Input: {[}
 * Output: 3 --> Unmatched '}' bracket
 */

string isBalanced(string str){
    stack<pair<char, int>> stack;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '[' || str[i] == '(' || str[i] == '{')
            stack.push({str[i], i});
        else if(str[i] == ']' || str[i] == ')' || str[i] == '}'){
            if(stack.empty())
                return to_string(i+1);
            char top = stack.top().first;
            stack.pop();
            if(top == '[' && str[i] != ']' || top == '(' && str[i] != ')' || top == '{' && str[i] != '}')
                return to_string(i+1);
        }
    }
    return "Success";
};

int main(){
    string str;
    int n = str.length();
    cout << "Enter string: ", cin >> str;
    cout << isBalanced(str) << endl;
    return 0;
}



